//Jacob Fallin
//I pledge my honor that I have abided by the Stevens Honor System

const todo = require("./todo");
const connection = require("./mongoConnection");

const main = async() => {

	
	try {
		// console.log("Removing All\n");
		// await todo.removeAll();
		//console.log("Adding Dinosaur\n");
		const dino = await todo.createTask("Ponder Dinosaurs", "Has Anyone Really Been Far Even as Decided to Use Even Go Want to do Look More Like?");
		console.log(dino);
		//console.log("\n");

		//console.log("Adding Pokemon\n");
		const pokemon = await todo.createTask("Play Pokemon with Twitch TV", "Should we revive Helix?");
		//console.log("Pokemon Added\n")

		//console.log("Query Began\n");
		const query1 = await todo.getAllTasks();
		console.log(query1);
		//console.log("Query Finished\n");

		//console.log("Removing Dinosaur\n");
		await todo.removeTask(dino._id);
		//console.log("Dinosaur Removed\n");

		//console.log("Query Began\n");
		const query2 = await todo.getAllTasks();
		console.log(query2);
		//console.log("Query Finished\n");

		const e

		//console.log("Updating\n");
		const update = await todo.completeTask(pokemon._id);
		console.log(update);
		//console.log("Update Finished\n");

		const db = await connection();
		await db.serverConfig.close();

		//console.log("Done");

	} catch(error) {
		console.error(error);
	}

};
main();

// main().catch(error => {
// 	console.error(error);
// });