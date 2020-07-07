const Comission = require('../models/Comission');
const Project = require('../models/Project');
const Member= require('../models/Member');

module.exports = {
    
    async store (request, response) { 
        try{   
            const {title, description } = request.body
        
            const comission = await Comission.create({
                title, 
                description,
            });
    
            await comission.save();

            return response.send({ comission });
        } catch (err) {
            return response.status(400).send({ error: 'Error creating new comission'});
        };
    },

    async index (request,response) {
        try{
            const comissions = await Comission.find();
    
            return response.send({ comissions });
        } catch (err) {
            return response.status(400).send({ error: 'Error loading comissions'});
        };
    },

    async update (request, response) {
        try{
            const { title, description } = request.body;
    
            const comission = await Comission.findByIdAndUpdate(request.params.comissionId, { 
                title,
                description,
            }, { new: true });
    
            return response.send({ comission });
        } catch (err) {
            return response.status(400).send({ error: 'Error updating comission'});
        };
    },

    async delete (request, response) {
        try{
            await Comission.findByIdAndRemove(request.params.comissionId);
    
            return response.send();
        } catch (err) {
            return response.status(400).send({ error: 'Error deleting comission'});
        };
    },

    async insertMember(request, response) {

        const member = await Member.findOne({ _id: request.body.memberId })

        if(!member)
            return response.status(400).send({ error: 'Member does not exist' });

        if(await Comission.findOne({ member }))
            return response.status(400).send({ error: 'Member is already in this comission' });

        //inserir membro
        const updatedComission = await Comission.updateOne(
            { _id: request.params.comissionId },
            { $push: { member: request.body.memberId } }
        );

        response.json(updatedComission);

    },

     async removeMember(request, response){
        try {
            const member = await Member.findOne({ _id: request.body.memberId });

            if(!member)
                return response.status(400).send({ error: 'Member does not exist' });

            const estaNaComissao = await Comission.findOne({ _id: request.body.comissionId, member: { $in: [memberId]} });

            if(!estaNaComissao)
                return response.status(400).send({ error: 'Member is not on this comission' });

            const updatedComission = await Comission.updateOne(
                { _id: request.params.comissionId },
                { $pull: { member: request.body.memberId } }
            )
            response.json(updatedComission);
        }
        catch (err) {
            response.json(err)
        }
    },

    async insertProject(request, response) {

        const project = await Project.findOne({ _id: request.body.projectId })

        if(!project)
            return response.status(400).send({ error: 'Project does not exist' });

        if(await Comission.findOne({ project }))
            return response.status(400).send({ error: 'Project is already in this comission' });

        //inserir membro
        const updatedComission = await Comission.updateOne(
            { _id: request.params.comissionId },
            { $push: { project: request.body.projectId } }
        );

        response.json(updatedComission);

    },

     async removeProject(request, response){
        try {
            const project = await Project.findOne({ _id: request.body.projectId });

            if(!project)
                return response.status(400).send({ error: 'Project does not exist' });

            const estaNaComissao = await Comission.findOne({ _id: request.body.comissionId, project: { $in: [projectId]} });

            if(!estaNaComissao)
                return response.status(400).send({ error: 'Member is not on this comission' });

            const updatedComission = await Comission.updateOne(
                { _id: request.params.comissionId },
                { $pull: { project: request.body.projectId } }
            )
            response.json(updatedComission);
        }
        catch (err) {
            response.json(err)
        }
    }

}