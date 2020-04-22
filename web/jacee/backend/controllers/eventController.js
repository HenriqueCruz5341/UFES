const Event = require("../models/Event")
const EventPart = require("../models/EventPart")
const Student = require("../models/Student")
const { eventValidation } = require("../validation")

module.exports = {

    async index(req, res) { // get all events
        const events = await Event.find().populate("eventPart")
        res.json({ events })
    },

    async studentEventsShow(req, res) { // get all events of an student

        const student = await Student.findOne({ _id: req.params.idStudent })
        if (!req.user.admin && req.user._id != student.person) {
            return res.status(401).send("access denied, this user is not allowed to do this action")
        }

        const events = await Event.find({
            enrolledStudents: {
                $in: [req.params.idStudent]
            }
        }).populate("eventPart")

        res.json({ events })
    },

    async show(req, res) {
        const event = await Event.find({ _id: req.params.idEvent }).populate("eventPart  enrolledStudents enrolledPeople")
        res.json({ event })
    },

    async store(req, res) { // add a event

        if (!req.user.admin) {
            return res.status(401).send("access denied, just admins can do that")
        }

        const { error } = eventValidation(req.body)
        if (error) {
            return res.status(400).send(error.details[0].message)
        }

        const event = new Event({
            title: req.body.title,
            previousKnowledge: req.body.previousKnowledge,
            vacancies: req.body.vacancies,
            description: req.body.description,
            material: req.body.material,
            responsable: req.body.responsable,
            type: req.body.type
        })
        try {
            const savedEvent = await event.save()
            res.send(savedEvent)
        }
        catch (err) {
            res.status(400).send(err)
        }
    },

    async update(req, res) {  // update main event data
        try {

            if (!req.user.admin) {
                return res.status(401).send("access denied, just admins can do that")
            }

            const { error } = eventValidation(req.body)
            if (error) {
                return res.status(400).send(error.details[0].message)
            }

            await Event.findByIdAndUpdate({ _id: req.params.idEvent }, {
                title: req.body.title,
                previousKnowledge: req.body.previousKnowledge,
                vacancies: req.body.vacancies,
                description: req.body.description,
                material: req.body.material,
                responsable: req.body.responsable,
                type: req.body.type
            })

            res.status(200).send("Success!")
        }
        catch (err) {
            res.status(500).send("Fail!")
            console.log(err)
        }
    },

    async enrollStudent(req, res) {

        const student = await Student.findOne({ _id: req.body.idStudent })
        if (!req.user.admin && req.user._id != student.person) {
            return res.status(401).send("access denied, this user can not enroll another user")
        }

        //verify if the student already paid jacee           
        if (!student.paid) {
            return res.status(401).send("The student must pay the registration fee before registering for the events")
        }
        //verify if the student is already enrolled in the event
        const studentExist = await Event.findOne({
            $and: [
                { _id: req.params.idEvent },
                {
                    $or: [
                        {
                            enrolledStudents: {
                                $in: [req.body.idStudent]
                            }
                        },
                        { vacancies: { $lte: 0 } }
                    ]
                }
            ]

        })
        if (studentExist) {
            return res.status(400).send("This student can't register for this event")
        }
        //enroll student
        const updatedEvent = await Event.updateOne(
            { _id: req.params.idEvent },
            {
                $push: { enrolledStudents: req.body.idStudent, enrolledPeople: req.body.idPerson },
                $inc: { vacancies: -1 }
            }
        )

        res.json(updatedEvent)


    },

    async destroy(req, res) {
        try {

            if (!req.user.admin) {
                return res.status(401).send("access denied, this user is not allowed to do this action")
            }

            const removedEvent = await Event.findOneAndDelete({ _id: req.params.idEvent })
            await removedEvent.eventPart.forEach(async element => {
                await EventPart.deleteOne({ _id: element })
            });
            res.json({
                event: removedEvent
            })

        } catch (err) {
            res.json({ message: err })
        }
    },

    async unenrollUniqueEvent(req, res) {
        try {
            const student = await Student.findOne({ _id: req.body.idStudent })
            if (!req.user.admin && req.user._id != student.person) {
                return res.status(401).send("access denied, this user can not unenroll another user")
            }

            const updatedEvent = await Event.updateOne(
                { _id: req.params.idEvent },
                {
                    $pull: { enrolledStudents: req.body.idStudent, enrolledPeople: req.body.idPerson },
                    $inc: { vacancies: 1 }
                }
            )
            res.json(updatedEvent)
        }
        catch (err) {
            res.json(err)
        }
    },

    async unenrollAllEvents(req, res) {
        try {

            const student = await Student.findOne({ _id: req.body.idStudent })
            if (!req.user.admin && req.user._id != student.person) {
                return res.status(401).send("access denied, this user can not unenroll another user")
            }

            const updatedEvents = await Event.updateMany(
                {
                    enrolledStudents: {
                        $in: [req.body.idStudent]
                    }
                },
                {
                    $pull: { enrolledStudents: req.body.idStudent, enrolledPeople: req.body.idPerson },
                    $inc: { vacancies: 1 }
                }
            )
            res.json(updatedEvents)
        }
        catch (err) {
            res.json(err)
        }
    },

}