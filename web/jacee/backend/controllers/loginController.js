const Person = require("../models/Person")
const bcrypt = require("bcryptjs")
const nodemailer = require("nodemailer")
const jwt = require("jsonwebtoken")
const {loginValidation, emailValidation, changePasswordValidation} = require("../validation")
const {randomString} = require("../utils/controllersFunctions")

module.exports = {

    async  store(req, res){
        //Validate of login
        const { error } = loginValidation(req.body)
        if (error) {
            return res.status(400).send(error.details[0].message)
        }
        //checking if the email exists
        const person = await Person.findOne({ email: req.body.email }).select("password admin")
        if (!person) {
            return res.status(400).send("Email is not found")
        }
        //password is correct
        const validPass = await bcrypt.compare(req.body.password, person.password)
        if (!validPass) {
            return res.status(400).send("invalid password")
        }
        // create and assign a token
        // const token = jwt.sign({ _id: person._id, admin: person.admin}, process.env.TOKEN_SECRET,{ expiresIn: '1h' })
        const token = jwt.sign({ _id: person._id, admin: person.admin }, process.env.TOKEN_SECRET)
        res.header("auth-token", token).send(token)
    },

    async forgotPassword(req,res){
        const { error } = emailValidation(req.body)
        if (error) {
            return res.status(400).send(error.details[0].message)
        }

        const person = await Person.findOne({ email: req.body.email })
        if (!person) {
            return res.status(400).send("Email is not found")
        }

        const transporter = nodemailer.createTransport({
            host: "smtp.gmail.com",
            port: 465,
            secure: true,
            auth:{
                user: process.env.EMAIL,
                pass: process.env.EMAIL_PASSWORD
            }

        })

        const newPassword = randomString()
        //Hash passwords
        const salt = await bcrypt.genSalt(10)
        const hashedPassword = await bcrypt.hash(newPassword, salt)
        
        Person.updateOne(
            { email: req.body.email },
            { password: hashedPassword }
        ).then((updatedPassword)=>{
            console.log(updatedPassword)
        }).catch((err)=>{
            console.log(err)
        })


        const message = await transporter.sendMail({
            from: process.env.EMAIL,
            to: req.body.email,
            subject: "Pedido de alteração de senha - Jacee",
            html: `Olá recebemos um pedido de alteração de senha, sua nova senha temporária é ${newPassword}.<br>
                    Clique nesse <a href = "localhost:3000"> link </a> para alterar sua senha.`
        })

        res.json({message})

    },

    async newPassword(req,res){
        const { error } = changePasswordValidation(req.body)
        if (error) {
            return res.status(400).send(error.details[0].message)
        }

        const person = await Person.findOne({ email: req.body.email }).select("password admin")
        if (!person) {
            return res.status(400).send("Email is not found")
        }

        //password is correct
        const validOldPass = await bcrypt.compare(req.body.oldPassword, person.password)
        if (!validOldPass) {
            return res.status(400).send("invalid temporary password")
        }

        const salt = await bcrypt.genSalt(10)
        const hashedPassword = await bcrypt.hash(req.body.newPassword, salt)
        
        Person.updateOne(
            { email: req.body.email },
            { password: hashedPassword }
        ).then(()=>{
            console.log("success to update password!")
        }).catch((err)=>{
            console.log(err)
        })



        // create and assign a token
        // const token = jwt.sign({ _id: person._id, admin: person.admin }, process.env.TOKEN_SECRET,{ expiresIn: '1h' })
        const token = jwt.sign({ _id: person._id, admin: person.admin }, process.env.TOKEN_SECRET)
        res.header("auth-token", token).send(token)
        
        
        
    }

}