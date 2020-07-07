const Documents = require("../models/Documents");
const File = require("../models/File");
const { deleteFile } = require("../utils/functions");

module.exports = {
  async index(req, res) {
    const documents = await Documents.find().populate("files");
    res.json({ documents });
  },

  async show(req, res) {
    const document = await Documents.findOne({ _id: req.params.id }).populate(
      "files"
    );
    res.json({ document });
  },

  async store(req, res) {
    console.log(req.body);
    const document = new Documents({
      title: req.body.title,
    });

    try {
      const savedDocument = await document.save();
      res.send({ document: savedDocument._id });
    } catch (err) {
      res.status(400).send(err);
    }
  },

  async addFile(req, res) {
    const { originalname: name, size, filename: key } = req.file;
    const file = new File({
      name,
      size,
      key,
    });

    try {
      const savedFile = await file.save();

      try {
        const updatedDocument = await Documents.updateOne(
          { _id: req.params.id },
          { $push: { files: savedFile } }
        ).populate("files");

        res.json({ updatedDocument });
      } catch (err) {
        const f = await File.findOne({ _id: savedFile });
        deleteFile(f, "documents");
        await File.deleteOne({ _id: savedFile });
        res.status(400).send(err);
      }
    } catch (err) {
      res.status(400).send(err);
    }
  },

  async removeFile(req, res) {
    const file = await File.findOne({ _id: req.body.idFile });

    if (file) {
      deleteFile(file, "documents");

      try {
        await File.deleteOne({ _id: req.body.idFile });

        try {
          const updatedDocument = await Documents.updateOne(
            { _id: req.params.id },
            { $pull: { files: req.body.idFile } }
          ).populate("files");

          res.json({ updatedDocument });
        } catch (err) {
          res.status(400).send(err);
        }
      } catch (err) {
        res.status(400).send(err);
      }
    } else {
      res.status(404).send("file not found in db.");
    }
  },

  async update(req, res) {
    try {
      const updatedDocument = await Documents.updateOne(
        { _id: req.params.id },
        { title: req.body.title }
      );

      res.json({ updatedDocument });
    } catch (err) {
      res.status(400).send(err);
    }
  },

  async destroy(req, res) {
    //delete file from server
    const document = await Documents.findOne({ _id: req.params.id }).populate(
      "files"
    );
    if (document) {
      document.files.forEach(async (file) => {
        deleteFile(file, "documents");

        //delete file from db
        try {
          await File.deleteOne({ _id: file._id });
        } catch (err) {
          console.log(err);
        }
      });

      //delete document from db
      try {
        const removedDocument = await Documents.deleteOne({
          _id: req.params.id,
        });
        res.json({ document: removedDocument });
      } catch (err) {
        res.json({ message: err });
      }
    } else {
      res.status(404).send("documentId not found in db.");
    }
  },
};
