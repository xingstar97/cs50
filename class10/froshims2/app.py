from flask import Flask, render_template, request

app = Flask("__name__")

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
def register():
    if not request.form.get("name") or not request.form.get("sport") in SPORTS:
        return render_template("failed.html")
    return render_template("success.html")
