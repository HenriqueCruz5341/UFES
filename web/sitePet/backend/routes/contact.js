const router = require("express").Router();
const contactContoller = require("../controllers/contactController");

router.post("/", contactContoller.sendEmail);

module.exports = router;
