const router = require("express").Router();
const fileController = require("../controllers/fileController");
const multer = require("multer");
const multerConfig = require("../utils/multer");

// const upload = multer({ dest: "./public/data/uploads/" });

// router.post("/", upload.single("file"), (req, res) => {
//   console.log(req.file);
// });

router.get("/", fileController.index);
router.post("/", multer(multerConfig).single("file"), fileController.store);
router.delete("/:id", fileController.destroy);

module.exports = router;
