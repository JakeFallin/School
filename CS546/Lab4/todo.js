//Jacob Fallin
//I pledge my honor that I have abided by the Stevens Honor System

const dbConnection = require("./mongoConnection");
const mongoCollections = require("./mongoCollections");
const uuidv4 = require('uuid/v4');
const todo = mongoCollections.todoItems;


module.exports = {
	

	async createTask(title, description) {

		if(!title) throw "You must provide a title";
		if(!description) throw "You mus provide a description";
		
		let uuid = uuidv4();
		const todoCollection = await todo();

		const newTask = {
			_id: uuid,
			title: title,
			description: description,
			completed: false,
			completedAt: null
		};

		const insert = await todoCollection.insertOne(newTask);
		if(insert.insertedCount === 0) throw "Could not insert new Task";
		
		const t = await this.getTask(uuid);
		return t;
	},

	async getAllTasks() {

		const todoCollection = await todo();
		const items = await todoCollection.find({}).toArray();
		return items;
	},

	async getTask(id) {

		if(!id) throw "You must provide an id";

		const todoCollection = await todo();
		const item = await todoCollection.findOne({_id:id});
		if(item === null) throw "No item found with that id";
		return item;
	},

	async completeTask(taskId) {

		if(!taskId) throw "You must provide a taskId";
		const todoCollection = await todo();
		var date = new Date().toLocaleString();
		const updatedTask = {
			$set: {
			completed: true,
			completedAt: date
			}	
		};

		const update = await todoCollection.updateOne({_id:taskId}, updatedTask);
		if(update.modifiedCount === 0) throw "Could not update task";

		return await this.getTask(taskId);


	},

	async removeTask(id) {

		if(!id) throw "You must provide an id";

		const todoCollection = await todo();
		const deleteInfo = await todoCollection.removeOne({_id:id});
		if(deleteInfo.deletedCount === 0) throw 'Could not delete ${id}';
	}
	// },

	// async removeAll() {

	// 	const todoCollection = await todo();
	// 	const deleted = await todoCollection.remove({});

	// }

};