const express = require("express");
const r = express.Router();
const data = require("../data/index");
const recipeData = data.recipes;
const bodyparser = require('body-parser');


r.get("/recipes/:id", async (req, res) => {
  try {
    const recipe = await recipeData.getRecipeByID(req.params.id);
    res.json(recipe);
  } catch (e) {
    console.log(e);
    res.status(500).json({error: e});
  }
});

r.get("/recipes", async (req, res) => {
  try {
  	const recipeList = await recipeData.getAllRecipes();
    res.json(recipeList);
  } catch(e) {
    res.status(500).json({error: e});
  }
});

r.post("/recipes", async (req, res) => {
  try {
    let recipeBody = req.body;
    let recipe = await recipeData.postRecipe(recipeBody);
    res.json(recipe);
  } catch(e) {
    res.status(500).json({error: e});
  }
});

r.put("/recipes/:id", async (req, res) => {
  try {
    let updatedRecipe = await recipeData.putRecipe(req.params.id, req.body);
    res.json(updatedRecipe);
  } catch(e) {
    res.status(500).json({error: e});
  }
});

r.patch("/recipes/:id", async (req, res) => {
  try {
    let updatedRecipe = await recipeData.patchRecipe(req.params.id, req.body);
        res.status(200).json(updatedRecipe);
  } catch(e) {
    res.status(500).json({error: e});
  }
});

r.delete("/recipes/:id", async (req, res) => {
    try {
        await recipeData.deleteRecipe(req.params.id);
        res.status(200).json({message : "item deleted"});
    } catch(err) {
    res.status(500).json({error: e});
    }
});

module.exports = r;
