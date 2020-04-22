const mongoose = require("mongoose")
const personSchema = mongoose.Schema({
    name:{
        type: String,
        required: true,
        min: 2,
        max: 150
    },
    email:{
        type: String,
        required: true,
    },
    password:{
        type: String,
        min: 6,
        select: false,
        default: "defaultPassword" 
    },
    admin:{
        type: Boolean,
        default: false, 
    },
    phone:{
        type: String,
        max: 15,
        min: 11
    },
    date:{
        type: Date,
        default: Date.now
    }
})

module.exports = mongoose.model("Person", personSchema)