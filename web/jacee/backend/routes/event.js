const router = require("express").Router();
const verify = require("../verifyToken");
const eventController = require("../controllers/eventController");
const eventPartController = require("../controllers/eventPartController");

router.get("/", eventController.index);
router.get("/studentEvents/:idStudent",verify,eventController.studentEventsShow);
router.get("/:idEvent",verify, eventController.show);
router.post("/", verify, eventController.store);
router.post("/addEventPart/:idEvent", verify, eventPartController.store);
router.put("/:idEvent", verify, eventController.update);
router.put("/updateEventPart/:idEventPart", verify, eventPartController.update);
router.patch("/enrollStudent/:idEvent", verify, eventController.enrollStudent);
router.patch("/unenrollStudent/:idEvent", verify, eventController.unenrollUniqueEvent); // unenroll  unique event
router.patch("/unenrollStudent/", verify, eventController.unenrollAllEvents); // unenroll all events
router.patch("/markPresence/:idEventPart",verify,eventPartController.markPresence);
router.delete("/deleteEventPart/:idEventPart",verify,eventPartController.destroy);
router.delete("/:idEvent", verify, eventController.destroy);

module.exports = router;
