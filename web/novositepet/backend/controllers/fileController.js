const File = require("../models/File");

module.exports = {
  async index(req, res) {
    const files = await File.find();
    res.json({ files });
  },

  async store(req, res) {
    console.log(req.file);
    const { originalname: name, size, filename: key } = req.file;

    const file = await File.create({
      name,
      size,
      key,
    });
    return res.json(file);
  },

  async destroy(req, res) {
    try {
      const removedFile = await File.deleteOne({
        _id: req.params.id,
      });
      res.json({ file: removedFile });
    } catch (err) {
      res.json({ message: err });
    }
  },
};
