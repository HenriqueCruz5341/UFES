const router = require("express").Router();
const documentsController = require("../controllers/documentsController");
const multer = require("multer");
const { multerConfig } = require("../utils/multer");
const verify = require("../utils/verifyToken");

router.get("/", documentsController.index);
router.get("/:id", documentsController.show);
router.post("/", verify, documentsController.store);
router.patch(
  "/addFile/:id",
  verify,
  multer(multerConfig("pdf")).single("file"),
  documentsController.addFile
);
router.patch("/removeFile/:id", verify, documentsController.removeFile);
router.put("/:id", verify, documentsController.update);
router.delete("/:id", verify, documentsController.destroy);

module.exports = router;
