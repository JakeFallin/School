const about = require("./about");
const story = require("./story");
const education = require("./education");

const constructorMethod = app => {
  app.use("/about", about);

  app.use("/story", story);

  app.use("/education", education);

  app.use("*", (req, res) => {
    res.status(404).json({ error: "Not found" });
  });
};

module.exports = constructorMethod;