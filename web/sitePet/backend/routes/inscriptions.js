const router = require("express").Router();
const inscriptionsController = require("../controllers/inscriptionsController");
const multer = require("multer");
const { multerConfig } = require("../utils/multer");

router.get("/", inscriptionsController.index);
router.get("/:id", inscriptionsController.show);
router.post(
  "/",
  multer(multerConfig("zip")).single("file"),
  inscriptionsController.store
);
router.put("/:id", inscriptionsController.update);
router.delete("/:id", inscriptionsController.destroy);
router.patch("/udateInscription/:id", inscriptionsController.updateInscription);

module.exports = router;
