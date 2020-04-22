const mongoose = require("mongoose")
const eventSchema = mongoose.Schema({

    title: {
        type: String,
        required: true
    },
    previousKnowledge: [{
        type: String,
        default: "Nenhum"
    }],
    vacancies: {
        type: Number,
        required: true
    },
    
    enrolledStudents: [{
       type: mongoose.Schema.Types.ObjectId,
       ref: "Student"
    }],

    enrolledPeople:[{
        type: mongoose.Schema.Types.ObjectId,
        ref: "Person"
    }],
    
    eventPart: [{
        type: mongoose.Schema.Types.ObjectId,
        ref: "EventPart"
    }],
    responsable: String,
    description: String,
    material: String,
    type: String
})

module.exports = mongoose.model("Event", eventSchema)

