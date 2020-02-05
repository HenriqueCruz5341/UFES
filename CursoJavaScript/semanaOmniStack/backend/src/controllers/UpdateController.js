const Dev = require('../models/Dev');
const parseStringAsArray = require('../utils/parseStringAsArray');


module.exports = {
    async index(request, response){
        const {github_username, name, techs} = request.body;
        
        if(name){
            let dev = await Dev.updateOne({github_username}, { $set: { name } });
            console.log(name);
        }

        if(techs){
            let techsArray = parseStringAsArray(techs);
            console.log(techsArray);
            let dev = await Dev.updateOne({github_username}, { $set: { techs: techsArray } });
        }

        return response.json();
    }
}