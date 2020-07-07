const router = require("express").Router();
const projectController = require("../controllers/ProjectController");

router.post("/", projectController.store);
router.get("/", projectController.index);
router.put("/:projectId", projectController.update);
router.delete("/:projectId", projectController.delete);

module.exports = router;
