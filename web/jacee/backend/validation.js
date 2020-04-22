//validation
const Joi = require('@hapi/joi')
const {personValidation, studentValidation} = require("./utils/validationFunctions")
Joi.objectId = require('joi-objectid')(Joi)


//Register Validation
const registerValidation = (data)=>{
    const personValidate = personValidation(data)
    const schema = Joi.object({
        password: Joi.string().min(6).required()
    })
    return Object.assign({}, personValidate, schema.validate({password:data.password})) 
}
const updateRegisterValidation = (data)=>{    
    return personValidation(data)
}
const loginValidation = (data)=>{
    const schema = Joi.object({
        email: Joi.string().min(6).required().email(),
        password: Joi.string().min(6).required()
    })
    return schema.validate(data)
}
const emailValidation = (data)=>{
    const schema = Joi.object({
        email: Joi.string().min(6).required().email(),
    })

    return schema.validate(data)
}
const changePasswordValidation = data=>{
    const schema = Joi.object({
        email: Joi.string().min(6).required().email(),
        oldPassword:  Joi.string().min(6).required(),
        newPassword:  Joi.string().min(6).required(),
    })

    return schema.validate(data)
}
const registerStudentValidation = (data)=> {
    const personValidate = personValidation(data)
    const studentValidate = studentValidation(data)
    const schema = Joi.object({
        password: Joi.string().min(6).required()
    })
    return Object.assign({}, personValidate,studentValidate, schema.validate({password:data.password})) 
}
const updateStudentValidation = (data)=> {
    const personValidate = personValidation(data)
    const studentValidate = studentValidation(data)
    return Object.assign({}, personValidate,studentValidate) 
}
const eventPartValidation = (data)=>{
    const schema = Joi.object({
        duration: Joi.number().required(),
        date: Joi.date().required(),
        local: Joi.string().required(),
        students: Joi.array().items(Joi.objectId())
    })
    return schema.validate(data)
}
const eventValidation = (data)=>{
    const schema = Joi.object({
        title: Joi.string().required(),
        previousKnowledge: Joi.string(),
        vacancies: Joi.number().required(), 
        eventPart: Joi.array().items(Joi.objectId()),
        description: Joi.string(),
        material: Joi.string(),
        responsable: Joi.string(),
        type: Joi.string(),
        enrolledStudents: Joi.array().items(Joi.objectId()),
        enrolledPeople: Joi.array().items(Joi.objectId())
    })

    return schema.validate(data)
}

module.exports.registerValidation = registerValidation
module.exports.emailValidation = emailValidation
module.exports.updateRegisterValidation = updateRegisterValidation
module.exports.loginValidation = loginValidation
module.exports.registerStudentValidation = registerStudentValidation
module.exports.updateStudentValidation = updateStudentValidation
module.exports.eventPartValidation = eventPartValidation
module.exports.eventValidation = eventValidation
module.exports.changePasswordValidation = changePasswordValidation