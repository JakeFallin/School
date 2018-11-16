const routes = require('./users');

const constructorMethod = app => {
	app.use('/', routes);
	app.use('*', (req, res) => {
		res.status(404).json({error: 'Unknown route'});
	})
}

module.exports = constructorMethod;