const router = require("express").Router();
const inscriptionsController = require("../controllers/inscriptionsController");
const multer = require("multer");
const multerConfig = require("../utils/multer");

router.get("/", inscriptionsController.index);
router.get("/:id", inscriptionsController.show);
router.get("/downloadDocuments", inscriptionsController.download);
router.post(
  "/",
  multer(multerConfig).single("file"),
  inscriptionsController.store
);
router.put("/:id", inscriptionsController.update);
router.delete("/:id", inscriptionsController.destroy);
router.patch("/udateInscription/:id", inscriptionsController.updateInscription);

module.exports = router;
