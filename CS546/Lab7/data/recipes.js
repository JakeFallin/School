const mongoCollections = require("../mongoCollections");
const myRecipes = mongoCollections.recipes;
const uuid = require("uuid/v4")


let e = {

	async getAllRecipes() {
			const recipes = await myRecipes();
			let allRecipes = await recipes.find({}).toArray();
			let formatted = [];
			for(let i = 0; i < allRecipes.length; i++) {
				formatted.push({_id: allRecipes[i]._id, title: allRecipes[i].title});
			}
			return formatted;
		
	}, 

	async getRecipeByID(id) {
		
		if(typeof id !== "string") {
			throw ("ID is not a valid type");
		}
		if(id == '') {
				throw ("Empty ID");
		}
		const recipes = await myRecipes();
		return recipe = await recipes.findOne({_id: id});
		
		 
	},

	async postRecipe(r) {
			if(typeof r.title !== "string" || !r.title) {
				throw ("Invalid title");
			}
			if(!Array.isArray(r.ingredients) || !r.ingredients) {
				throw ("Invalid ingredients");
			}
			if(!Array.isArray(r.steps) || !r.steps) {
				throw ("Invalid steps");
			}
			r.ingredients.forEach((i) => {
				if(typeof i.name !== "string" || !i.name) {
					throw ("Not every ingredient has a name");
				}
				if(typeof i.amount !== "string" || !i.amount) {
					throw ("Not every ingredient has an amount");
				}
			})
			r.steps.forEach((s) => {
				if(typeof s !== "string" || !s) {
					throw ("The step ${s} is invalid");
				}
			})

			const recipes = await myRecipes();
			let newR = {
				_id: uuid(),
				title: r.title,
				ingredients: r.ingredients,
				steps: r.steps
			}
			await recipes.insertOne(newR);
			return await this.getRecipeByID(id);

		
	},

	async putRecipe(id, r) {
				
			const u = {};

			if(r.title)
				u.title = r.title;
			if(r.ingredients)
				u.ingredients = r.ingredients;
			if(r.steps)
				u.steps = r.steps;



			if(typeof r.title !== "string" ) {
				throw ("Invalid title");
			}
			if(!Array.isArray(r.ingredients) || !r.ingredients) {
				throw ("Invalid ingredients");
			}
			if(!Array.isArray(r.steps) || !r.steps) {
				throw ("Invalid steps");
			}
			r.ingredients.forEach((i) => {
				if(typeof i.name !== "string" || !i.name) {
					throw ("Not every ingredient has a name");
				}
				if(typeof i.amount !== "string" || !i.amount) {
					throw ("Not every ingredient has an amount");
				}
			})
			r.steps.forEach((s) => {
				if(typeof s !== "string" || !s) {
					throw ("The step ${s} is invalid");
				}
			})

			let updateInfo = {
				$set: u
			};

			let updateC = {
				_id: id
			};
			const recipes = await myRecipes();
			await recipes.updateOne(updateC, updateInfo);
			return await this.getRecipeByID(id);


	},

	async patchRecipe(id, r) {
			let myR = {};
			if(typeof id !== "string" || !id) {
				throw ("Invalid id");
			}
			if(r.title) {
				if(typeof r.title !== "string" || !r.title) {
					throw ("Invalid title ${title}");
				}
				myR.title = r.title;
			}
			if(r.ingredients) {
				if(!Array.isArray(r.ingredients) || !r.ingredients) {
					throw ("Invalid ingredients");
				}

				r.ingredients.forEach((i) => {
					if(typeof i.name !== "string" || !i.name) {
						throw ("Not every ingredient has a name");
					}
					if(typeof i.amount !== "string" || !i.amount) {
						throw ("Not every ingredient has an amount");
					}
				})
				myR.ingredients = r.ingredients;
			}
			if(r.steps) {
				if(!Array.isArray(r.steps) || !r.steps) {
					throw ("Invalid steps");
				}
				r.steps.forEach((s) => {
					if(typeof s !== "string" || !s) {
						throw ("The step ${s} is invalid");
					}
				})
				myR.steps = r.steps;
			}
			const recipes = await myRecipes();
			let update = await recipes.findOneAndUpdate({_id:id}, {$set: myR});
			return await this.getRecipeByID(id);

	},

	async deleteRecipe(id) {
			if(typeof id !== "string" || !id) {
				throw ("Invalid id");
			}
			const recipes = await myRecipes();
			await recipes.deleteOne({_id: id});
	}
}	
module.exports = e;