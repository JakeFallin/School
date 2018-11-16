const recipes = require("./recipes");

const constructorMethod = app => {
  app.use("/", recipes);

  app.use("*", (req, res) => {
    res.status(404).json({ error: "Not2 found" });
  });
};

module.exports = constructorMethod;