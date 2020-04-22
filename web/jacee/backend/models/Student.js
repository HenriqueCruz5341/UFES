const mongoose = require("mongoose")
const studentSchema = new mongoose.Schema({
    cpf: {
        type: String,
        max: 14,
        min: 11,
        required: true
    },
    paid: {
        type: Boolean,
        default: false
    },
    hours: {
        type: Number,
        default: 0
    },
    person: {
        type: mongoose.Schema.Types.ObjectId,
        ref: "Person",
        required: true
    },
    date: {
        type: Date,
        default: Date.now
    },

    institution: String,
    course: String
})

module.exports = mongoose.model("Student", studentSchema)