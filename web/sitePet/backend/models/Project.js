const mongoose = require('mongoose');

const ProjectSchema = new mongoose.Schema({
    title: {
        type: String,
        required: true,
    },
    member: {
        type: mongoose.Schema.ObjectId,
        ref:'Member',
        required: true,
    },
    description: {
        type: String,
        required: true,
    },
    github_link: String,
    data_realizacao: Date
});

module.exports = mongoose.model('Project', ProjectSchema);