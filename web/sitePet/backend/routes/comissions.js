const router = require("express").Router();
const comissionController = require("../controllers/ComissionController");

router.post("/", comissionController.store);
router.get("/", comissionController.index);
router.put("/:comissionId", comissionController.update);
router.put("/insertMember/:comissionId", comissionController.insertMember);
router.put("/insertProject/:comissionId", comissionController.insertProject);
router.patch("/removeMember/:comissionId", comissionController.removeMember);
router.patch("/removeProject/:comissionId", comissionController.removeProject);
router.delete("/:comissionId", comissionController.delete);
router.put("/insertMember/:projectId", comissionController.insertMember);
router.patch("/removeMember/:projectId", comissionController.removeMember);

module.exports = router;
