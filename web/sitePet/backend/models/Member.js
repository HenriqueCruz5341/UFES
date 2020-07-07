const mongoose = require('mongoose');

const MemberSchema = new mongoose.Schema({
    name: {
        type: String,
        required: true,
    },
    email: {
        type: String,
        unique:true,
        required: true,
        lowercase: true,
    },
    whatsapp: {
        type: String,
        required: true,
    },
    start_pet: {
        type: Date,
        required: true,
    },
    end_pet: Date,
    active: {
        type: Boolean,
        required: true,
    }
});

module.exports = mongoose.model('Member', MemberSchema);