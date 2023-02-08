from flask import Flask, render_template, request

app = Flask("__name__")

@app.route("/")

def index():
    return render_template("index.html")

@app.route("/greet")
# add route for greet
def greet():
    name = request.args.get("name", "World")
    # default: World
    return render_template("greet.html", name = name)
