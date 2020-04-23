const File = require("../models/File");
const path = require("path");

module.exports = {
  async index(req, res) {
    const files = await File.find();
    res.json({ files });
  },

  async downloadInscription(req, res) {
    const file = await File.findOne({ _id: req.params.id });

    const pathFile = path.join(
      __dirname.slice(0, 34),
      `tmp/inscriptions/${file.key}`
    );

    res.sendFile(pathFile);
  },

  async downloadDocument(req, res) {
    const file = await File.findOne({ _id: req.params.id });

    const pathFile = path.join(
      __dirname.slice(0, 34),
      `tmp/documents/${file.key}`
    );

    res.sendFile(pathFile);
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
