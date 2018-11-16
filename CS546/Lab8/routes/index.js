var form = require("./form");
var result = require("./result");

const constructorMethod = (app) => {
	app.use("/", form);
	
	app.use("/result", result);
	
	app.use("*", (req,res) => {
		res.status(404).json({error: "Route doesn't exist"});
	});
};
module.exports = constructorMethod;