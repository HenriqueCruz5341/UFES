const Member = require('../models/Member');

module.exports = {
    
    async store (request, response) { 
        try{   
            const {name, email, whatsapp, start_pet, end_pet, active } = request.body
        
            const member = await Member.create({
                name,
                email,
                whatsapp,
                start_pet,
                end_pet,
                active
            });

            return response.json({ member });
        } catch (err) {
            return response.status(400).send({ error: 'Error creating new member'});
        };
    },

    async index (request,response) {
        try{
            const members = await Member.find();
    
            return response.send({ members });
        } catch (err) {
            return response.status(400).send({ error: 'Error loading members'});
        };
    },

    async update (request, response) {
        try{
            const { name, email, whatsapp, start_pet, end_pet, active } = request.body;
    
            const member = await Member.findByIdAndUpdate(request.params.memberId, { 
                name, 
                email, 
                whatsapp, 
                start_pet, 
                end_pet, 
                active 
            }, { new: true });
    
            return response.send({ member });
        } catch (err) {
            return response.status(400).send({ error: 'Error updating member'});
        };
    },

    async delete (request, response) {
        try{
            await Member.findByIdAndRemove(request.params.memberId);
    
            return response.send();
        } catch (err) {
            return response.status(400).send({ error: 'Error deleting member'});
        };
    }
}