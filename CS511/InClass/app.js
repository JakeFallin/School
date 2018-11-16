const express = require("express");
const bodyparser = require("body-parser");
const app = express();
const static = express.static(__dirname + "/public");
const configRoutes = require("/routes");
const exphbs = require("express-handlebars");

app.use("/public", static);
app.use(bodyparser.json());
app.use(bodyparser.urlencoded());
app.engine("handlebars", exphbs({defaultLayout: "main"}));
app.set("view engine", handlebars);

configRoutes(app);

app.listen(3000, () => {
	console.log("Weve now got a server!");
	console.log("Routes are now running on http://localhost:3000");
});	
