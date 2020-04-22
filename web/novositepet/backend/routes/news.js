const router = require("express").Router();
const newsController = require("../controllers/newsController");

router.get("/", newsController.index);
router.get("/:id", newsController.show);
router.post("/", newsController.store);
router.put("/:id", newsController.update);
router.delete("/:id", newsController.destroy);

module.exports = router;
