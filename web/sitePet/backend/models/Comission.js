const mongoose = require('mongoose');

const ComissionSchema = new mongoose.Schema({
    title: {
        type: String,
        required: true,
    },
    description: {
        type: String,
        required: true,
    },
    project: [{
        type: mongoose.Schema.Types.ObjectId,
        ref: 'Project',
    }],
     member: [{
         type: mongoose.Schema.Types.ObjectId,
         ref: 'Member',
    }]
});

module.exports = mongoose.model('Comission', ComissionSchema);