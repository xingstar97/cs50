from flask import Flask, render_template, request, redirect

app = Flask("__name__")

REGISTRAINTS={}

SPORTS = [
    "basketball",
    "football",
    "table tennis",
    "soccer"
]

@app.route("/")
def index():
    return render_template("index2.html", sports = SPORTS)

@app.route("/register", methods =["POST"])
def registerfjaspoidfjsa():
    name = request.form.get("name")
    sport = request.form.get("sport")
    if not name or not sport in SPORTS:
        return render_template("failed.html")
    REGISTRAINTS[name] = sport
    return redirect("/registraints")

@app.route("/registraints")
def registraints():
    return render_template("registraints.html", registraints = REGISTRAINTS)
