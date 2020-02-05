const Dev = require('../models/Dev');
const parseStringAsArray = require('../utils/parseStringAsArray');


module.exports = {
    async index(request, response){
        const {github_username, techs, latitude, longitude} = request.query;
        
        let dev = await Dev.deleteOne({github_username});

        return response.json();
    }
}