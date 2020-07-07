const router = require("express").Router();
const memberController = require("../controllers/MemberController");

router.post("/", memberController.store);
router.get("/", memberController.index);
router.put("/:memberId", memberController.update);
router.delete("/:memberId", memberController.delete);

module.exports = router;
