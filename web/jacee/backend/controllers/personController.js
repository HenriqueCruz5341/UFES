const Person = require("../models/Person")
const { registerValidation, updateRegisterValidation } = require("../validation")
const bcrypt = require("bcryptjs")


module.exports = {
    async store(req, res) {

        const { error } = registerValidation(req.body)
        if (error) {
            return res.status(400).send(error.details[0].message)
        }
        //Checking if the person is already in the database
        const emailExist = await Person.findOne({ email: req.body.email })
        if (emailExist) {
            return res.status(400).send("email already exists")
        }
        
        const salt = await bcrypt.genSalt(10)
        const hashedPassword = await bcrypt.hash(req.body.password, salt)

        //Create a new person
        const person = new Person({
            name: req.body.name,
            email: req.body.email,
            password: hashedPassword,
            admin: req.body.admin,
            phone: req.body.phone
        })
        try {
            const savedPerson = await person.save()
            res.send({ person: savedPerson._id })
        } catch (err) {
            res.status(400).send(err)
        }
    },


    async index(req, res) {
        const persons = await Person.find()
        return res.json({persons})
    },

    async show(req, res) {
        const person = await Person.findOne({ _id: req.params.id })
        res.json({ person })
    },
    async destroy(req,res){
        
        try{
            if(!req.user.admin && req.user._id  != req.params.idPerson){
               return res.status(401).send("this user is not allowed to delete another user")
            }       
            // validateUser(req,res)     
            const removedPerson = await Person.findOneAndDelete({_id: req.params.idPerson})
            res.json(removedPerson)
    
        }catch(err){
            console.log(err)
            res.json({message: err})
        }
    },


    async update(req, res){
        try {
            
            if(!req.user.admin && req.user._id  != req.params.id){
                return res.status(401).send("this user is not allowed to update another user")
             }

            const { error } = updateRegisterValidation(req.body)
            if (error) {
                return res.status(400).send(error.details[0].message)
            }
            const emailExist = await Person.findOne({ email: req.body.email })
            if (emailExist && emailExist._id != req.params.id) {
                return res.status(400).send("email already exists")
            }
    
            await Person.findOneAndUpdate({ _id: req.params.id }, {
                name: req.body.name,
                email: req.body.email,
                admin: req.body.admin,
                phone: req.body.phone
            })
            res.status(200).send("Success!")
        }
        catch(err){
            res.status(500).send("Fail!")
            console.log(err)
        }  
    }

}