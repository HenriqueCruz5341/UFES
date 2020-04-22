const Event = require("../models/Event")
const EventPart = require("../models/EventPart")
const Student = require("../models/Student")
const { eventPartValidation } = require("../validation")


module.exports = {

    async store(req, res) { // add a event's part		
        if (!req.user.admin) {
            return res.status(401).send("access denied, this user is not allowed to do this action")
        }

        const { error } = eventPartValidation(req.body)
        if (error) {
            return res.status(400).send(error.details[0].message)
        }
        try {
            const eventPart = new EventPart({
                duration: req.body.duration,
                date: req.body.date,
                local: req.body.local
            })
            const savedEventPart = await eventPart.save()
            const updatedEvent = await Event.updateOne(
                { _id: req.params.idEvent },
                { $push: { eventPart: savedEventPart._id } },
            )
            res.json(updatedEvent)
        }
        catch (err) {
            res.status(400).send(err)
        }
    },

    async update(req, res) {
        try {

            if (!req.user.admin) {
                return res.status(401).send("access denied, this user is not allowed to do this action")
            }

            const { error } = eventPartValidation(req.body)
            if (error) {
                return res.status(400).send(error.details[0].message)
            }

            const updateEventPart = await EventPart.findByIdAndUpdate({ _id: req.params.idEventPart }, {
                duration: req.body.duration,
                date: req.body.date,
                local: req.body.local
            })

            res.status(200).send("Success!")
        }
        catch (err) {
            res.status(500).send("Fail!")
            console.log(err)
        }
    },

    async markPresence(req, res) {
        try {

            const studentExist = await Event.findOne({
                $and: [
                    {
                        enrolledStudents: {
                            $in: [req.body.idStudent]
                        }
                    },
                    {
                        eventPart: {
                            $in: [req.params.idEventPart]
                        }
                    }

                ]
            })

            if (!studentExist) {
                return res.status(400).send("the student is not enrolled in this event")
            }

            // const updatedEventPart = await EventPart.findOneAndUpdate(
            //     {
            //         _id: req.params.idEventPart,

            //         students: {
            //             $not: {
            //                 $in: [req.body.idStudent]
            //             }
            //         }
            //     },
            //     {
            //         $push: {
            //             students: req.body.idStudent
            //         }
            //     }
            // )

            const studentPresent =  await EventPart.findOne({
                _id: req.params.idEventPart,
                students:{
                    $in: [req.body.idStudent]
                }
            })
            if (studentPresent) { 
                return res.status(400).send("the student is already marked as present")
            }
            else{

                const updatedEventPart = await EventPart.findOneAndUpdate(
                    { _id: req.params.idEventPart },
                    { $push: { students: req.body.idStudent } }
                )
                
                await Student.updateOne(
                    {
                        _id: req.body.idStudent
                    },
                    {
                        $inc: { hours: updatedEventPart.duration }
                    }
                ).then(() => console.log("Success in counting hours")).catch(err => console.log(err))

                res.json(updatedEventPart)
            }
        }
        catch (err) {
            res.json(err)
        }
    },
    async destroy(req, res) {
        try {

            if (!req.user.admin) {
                return res.status(401).send("this user is not allowed to do this action")
            }

            const removedEventPart = await EventPart.findOneAndDelete({ _id: req.params.idEventPart })
            await Event.updateOne(
                {
                    eventPart: {
                        $in: [removedEventPart._id]
                    }
                },
                {
                    $pull:
                    {
                        eventPart: removedEventPart._id
                    }
                }
            )


            res.json(removedEventPart)

        } catch (err) {
            console.log(err)
            res.json({ message: err })
        }
    }
}
