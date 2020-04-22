const mongoose = require("mongoose")
const eventPartSchema = mongoose.Schema({
    duration:{
        type: Number,
        required: true
    },
    date:{
        type: Date,
        default: Date.now
    },
    local:{
        type: String,
        required: true
    },
    students:[{
        type: mongoose.Schema.Types.ObjectId,
        ref: "Student"
    }]
})
module.exports = mongoose.model("EventPart", eventPartSchema)