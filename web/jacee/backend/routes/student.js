const router = require("express").Router()
const verify = require("../verifyToken")
const studentController = require("../controllers/studentController")

router.get("/", studentController.index)
router.get("/:id", studentController.show)
router.get("/getStudent/:idPerson", studentController.showStudentByPersonId)
router.put("/:id", verify, studentController.update)
router.patch("/paymentUpdate", verify, studentController.paymentUpdate)
router.post("/", studentController.store)
router.delete("/:idStudent", verify, studentController.destroy)



module.exports = router