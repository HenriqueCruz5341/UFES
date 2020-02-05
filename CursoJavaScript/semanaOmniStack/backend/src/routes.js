const { Router } = require('express');
const DevController = require('./controllers/DevController');
const SearchController = require('./controllers/SearchController');
const DeleteController = require('./controllers/DeleteController');
const UpdateController = require('./controllers/UpdateController');

const routes = Router();

routes.get('/devs', DevController.index);
routes.post('/devs', DevController.store);
routes.get('/search', SearchController.index);
routes.put('/devs', UpdateController.index);
routes.delete('/delete', DeleteController.index);

module.exports = routes;