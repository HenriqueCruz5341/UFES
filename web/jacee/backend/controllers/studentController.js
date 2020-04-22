const Person = require("../models/Person")
const Student = require("../models/Student")
const bcrypt = require("bcryptjs")
const { registerStudentValidation, updateStudentValidation } = require("../validation")
const { cpf } = require('cpf-cnpj-validator')

module.exports = {

    async index(req, res) {
        const students = await Student.find().populate("person")
        res.json({ students })
    },

    async show(req, res) {
        const student = await Student.findOne({ _id: req.params.id }).populate("person")
        res.json({ student })
    },

    async update(req, res) {
        try {

            if (!req.user.admin && req.user._id != req.params.idPerson) {
                return res.status(401).send("this user is not allowed to update another user")
            }

            const { error } = updateStudentValidation(req.body)
            if (error) {
                return res.status(400).send(error.details[0].message)
            }
            if (!cpf.isValid(req.body.cpf)) {
                return res.status(400).send("the informed cpf is not a valid one")
            }

            const updatedStudentData = await Student.findByIdAndUpdate({ _id: req.params.id }, {
                cpf: req.body.cpf,
                paid: req.body.paid,
                hours: req.body.hours,
                institution: req.body.institution,
                course: req.body.course
            })
            const updatedPersonData = await Person.findOneAndUpdate({ _id: updatedStudentData.person }, {
                name: req.body.name,
                email: req.body.email,
                accessLevel: req.body.accessLevel,
                phone: req.body.phone
            })
            res.status(200).send("Success!")
        }
        catch (err) {
            res.status(500).send("Fail!")
            console.log(err)
        }
    },


    async store(req, res) {
        const { error } = registerStudentValidation(req.body)
        if (error) {
            return res.status(400).send(error.details[0].message)
        }
        if (!cpf.isValid(req.body.cpf)) {
            return res.status(400).send("the informed cpf is not a valid one")
        }

        //Checking if the email is already in the database
        const emailExist = await Person.findOne({ email: req.body.email })
        if (emailExist) {
            return res.status(400).send("email already exists")
        }

        const cpfExist = await Person.findOne({ cpf: req.body.email })
        if (cpfExist) {
            return res.status(400).send("cpf already exists")
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
            const student = new Student({
                person: savedPerson._id,
                cpf: req.body.cpf,
                institution: req.body.institution,
                course: req.body.course,
                paid: req.body.paid,
                hours: req.body.hours
            })

            try {
                const savedStudent = await student.save()
                res.send({ student: savedStudent._id })
            }
            catch (err) {
                console.log(err)
            }

        } catch (err) {
            res.status(400).send(err)
        }
    },

    async destroy(req, res) {
        try {

            if (!req.user.admin && req.user._id != req.params.idPerson) {
                return res.status(401).send("this user is not allowed to delete another user")
            }

            const removedStudent = await Student.findOneAndDelete({ _id: req.params.idStudent })
            const removedPerson = await Person.findOneAndDelete({ _id: removedStudent.person })
            console.log(req.user)
            res.json({
                Student: removedStudent,
                Person: removedPerson
            })

        } catch (err) {
            console.log(err)
            res.json({ message: err })
        }
    },

    async paymentUpdate(req, res) {
        try {

            if (!req.user.admin) {
                return res.status(401).send("this user cannot change payment status, contact the admin")
            }

            await Student.updateOne(
                { _id: req.body.idStudent },
                { paid: req.body.paid }
            )
            res.send("Success!")
        }
        catch (err) {
            res.json({ err })
        }
    },
    async showStudentByPersonId(req, res) {
        const student = await Student.findOne({ person: req.params.idPerson }).populate("person")
        res.json({ student })
    }


}