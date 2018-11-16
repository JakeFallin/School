
const express = require('express');
const bp = require('body-parser');
const app = express();
const configRoutes = require('./routes');
const exphbs = require('express-handlebars');
const Handlebars = require('handlebars');
const cp = require('cookie-parser');
const static = express.static(__dirname + '/public');
const handlebarsInstance = exphbs.create({
    defaultLayout: 'main',
    helpers: {
        asJSON: (obj, spacing) => {
            if (typeof spacing === "number")
                return new Handlebars.SafeString(JSON.stringify(obj, null, spacing));
            return new Handlebars.SafeString(JSON.stringify(obj));
        }
    }
})

app.use('/public', static);
app.use(bp.json());
app.use(bp.urlencoded({extended: true}));
app.engine('handlebars', handlebarsInstance.engine);
app.set('view engine', 'handlebars');
app.use(cp());
configRoutes(app);

app.listen(3000, function() {
    console.log('Your server is now listening on port 3000! Go to http://localhost:3000 to access your routes.');
    if(process && process.send) process.send({done: true});
})