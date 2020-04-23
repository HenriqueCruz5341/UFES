const router = require("express").Router();
const fileController = require("../controllers/fileController");
const multer = require("multer");
const multerConfig = require("../utils/multer");

router.get("/", fileController.index);
router.get("/downloadDocument/:id", fileController.downloadDocument);
router.get("/downloadInscription/:id", fileController.downloadInscription);
router.post("/", multer(multerConfig).single("file"), fileController.store);
router.delete("/:id", fileController.destroy);

module.exports = router;
