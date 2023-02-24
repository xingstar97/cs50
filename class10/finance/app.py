import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


db.execute(
    "CREATE TABLE IF NOT EXISTS history(id integer PRIMARY KEY AUTOINCREMENT, user_id integer, Symbol text, Name text, Shares integer, Price float, Transacted numeric, FOREIGN KEY (user_id) REFERENCES users(id))"
)
# create index


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    if not session["user_id"]:
        return redirect("/login")
    stocks = db.execute(
        "SELECT Symbol, Name, SUM(Shares), SUM(Shares * Price) FROM history WHERE user_id = ? GROUP BY Symbol",
        session["user_id"],
    )
    currentprice = {}
    sum = 0
    for stock in stocks:
        price = lookup(stock["Symbol"])["price"]
        sum += price * stock["SUM(Shares)"]
        currentprice[stock["Symbol"]] = price
    spent = db.execute(
        "SELECT SUM(Shares*Price) FROM history WHERE user_id =?", session["user_id"]
    )
    spenVal = spent[0]["SUM(Shares*Price)"]
    cash = 10000
    if spenVal:
        cash = 10000 - spent[0]["SUM(Shares*Price)"]
    total = sum + cash
    return render_template(
        "index.html", stocks=stocks, currentprice=currentprice, cash=cash, total=total
    )


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        share = int(request.form.get("share"))
        if lookup(symbol) == None:
            return apology("Invalid symbol!", 400)
        # whether a variable is int
        elif not isinstance(share, int) or share < 0:
            return apology("Invalid share!", 400)
        price = lookup(symbol)["price"]
        name = lookup(symbol)["name"]
        cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
        if cash[0]["cash"] < price * share:
            return apology("Can't afford!", 400)
        cash = cash[0]["cash"] - price * share
        db.execute(
            "INSERT INTO history(user_id, Symbol, Name, Shares, Price, Transacted) VALUES (?,?,?,?,?,date())",
            session["user_id"],
            symbol,
            name,
            share,
            price,
        )
        db.execute("UPDATE users set cash = ? where id = ?", cash, session["user_id"])
        return redirect("/")
    return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    stocks = db.execute("SELECT * FROM history WHERE user_id = ?", session["user_id"])
    if stocks == None:
        return apology("No purchase history!", 400)
    return render_template("history.html", stocks=stocks)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        if lookup(symbol) == None:
            return apology("Invalid symbol!", 400)
        company = lookup(symbol)["name"]
        price = lookup(symbol)["price"]
        stock = lookup(symbol)["symbol"]
        return render_template("quoted.html", company=company, price=price, stock=stock)
    return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        name = request.form.get("username")
        password = request.form.get("password")
        confirm = request.form.get("confirm")
        names = db.execute("SELECT username FROM users")
        # nameList = [val["username"] for val in names]
        if not name:
            return apology("Invalid username!", 403)
        # names is a list of array, WRONG: if name in names
        for row in names:
            if name == row["username"]:
                return apology("Username already exists!", 403)
        if not password:
            return apology("Invalid password", 403)
        # compare strings
        elif password != confirm:
            return apology("Passwords do not mathch!", 403)
        db.execute(
            "INSERT INTO users (username, hash) VALUES(?,?)",
            name,
            generate_password_hash(password),
        )
        id = db.execute("SELECT id FROM users WHERE username =?", name)
        session["user_id"] = id[0]["id"]
        return redirect("/")
    return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    # request.method = get also use symbols
    symbols = db.execute(
        "SELECT Symbol FROM history WHERE user_id = ? GROUP BY Symbol",
        session["user_id"],
    )
    if request.method == "POST":
        symbol = request.form.get("symbol")
        share = int(request.form.get("shares"))
        stock = lookup(symbol)
        price = stock["price"]
        name = stock["name"]
        shares = db.execute(
            "SELECT SUM(Shares) FROM history WHERE user_id = ? and Symbol = ?",
            session["user_id"],
            symbol,
        )
        if not symbol:
            return apology("Invalid symbol!", 400)
        if symbol not in [sym["Symbol"] for sym in symbols]:
            return apology("Invalid symbol!", 400)
        if not isinstance(share, int) or share > shares[0]["SUM(Shares)"]:
            return apology("Invalid share!", 400)
        db.execute(
            "INSERT INTO history(user_id, Symbol, Name, Shares, Price, Transacted) VALUES (?,?,?,?,?,date())",
            session["user_id"],
            symbol,
            name,
            -share,
            price,
        )
        cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
        cash = cash[0]["cash"] + price * share
        db.execute("UPDATE users set cash = ? where id = ?", cash, session["user_id"])
        return redirect("/")
    return render_template("sell.html", symbols=symbols)
