const router = require("express").Router()
const loginController = require("../controllers/loginController")

router.post("/", loginController.store)
router.patch("/", loginController.forgotPassword) 
router.put("/", loginController.newPassword)


module.exports = router