const Project = require('../models/Project');
const Member = require('../models/Member');
const Comission =require('../models/Comission');

module.exports = {
    
    async store (request, response) { 
        try{   
            const { title, description, github_link, data_realizacao } = request.body
        
            const project = await Project.create({
                title, 
                description, 
                github_link, 
                data_realizacao
            });

            return response.json({ project });
        } catch (err) {
            return response.status(400).send({ error: 'Error creating new project'});
        };
    },

    async index (request,response) {
        try{
            const projects = await Project.find();
    
            return response.send({ projects });
        } catch (err) {
            return response.status(400).send({ error: 'Error loading projects'});
        };
    },

    async update (request, response) {
        try{
            const { title, description, github_link, data_realizacao } = request.body;
    
            const project = await Project.findByIdAndUpdate(request.params.projectId, { 
                title, 
                description, 
                github_link, 
                data_realizacao
            }, { new: true });
    
            return response.send({ project });
        } catch (err) {
            return response.status(400).send({ error: 'Error updating project'});
        };
    },

    async delete (request, response) {
        try{
            await Project.findByIdAndRemove(request.params.projectId);
    
            return response.send();
        } catch (err) {
            return response.status(400).send({ error: 'Error deleting project'});
        };
    },

    async insertMember(request, response) {

        const member = await Member.findOne({ _id: request.body.memberId })

        if(!member)
            return response.status(400).send({ error: 'Member does not exist' });

        if(await Project.findOne({ member }))
            return response.status(400).send({ error: 'Member is already in this project' });

        if(await Comission.findOne({ member })){
            //inserir membro
            const updatedProject = await Project.updateOne(
                { _id: request.params.projectId },
                { $push: { member: request.body.memberId } }
            );

            response.json(updatedProject);
        }

        return response.status(400).send({ error: 'Member is not on this comission' });
    },

     async removeMember(request, response){
        try {
            const estaNaComissao = await Comission.findOne({ _id: request.body.comissionId, member: { $in: [memberId]} });

            if(!estaNaComissao)
            return response.status(400).send({ error: 'Member is not on this comission' });

            const updatedProject= await Project.updateOne(
                { _id: request.params.projectId },
                { $pull: { member: request.body.memberId } }
            )
            response.json(updatedProject);
        }
        catch (err) {
            response.json(err)
        }
    },
}