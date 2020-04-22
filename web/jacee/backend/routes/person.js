const router = require("express").Router()
const verify = require("../verifyToken")
const personController = require("../controllers/personController")

router.post("/", personController.store)
router.get("/", personController.index)
router.get("/:id", personController.show)
router.put("/:id", verify, personController.update)
router.delete("/:idPerson", verify, personController.destroy)



module.exports = router