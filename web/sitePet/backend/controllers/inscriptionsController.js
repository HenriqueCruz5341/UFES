const Inscriptions = require("../models/Inscriptions");
const File = require("../models/File");
const fs = require("fs");
const path = require("path");
const { inscriptionsValidation } = require("../utils/validation");

module.exports = {
  async index(req, res) {
    const inscriptions = await Inscriptions.find().populate("documents");
    res.json({ inscriptions });
  },

  async show(req, res) {
    const inscription = await Inscriptions.findOne({ _id: req.params.id });
    res.json({ inscription });
  },

  async store(req, res) {
    const { error } = inscriptionsValidation(req.body);
    if (error) return res.status(400).send(error.details[0].message);

    const emailExist = await Inscriptions.findOne({ email: req.body.email });
    if (emailExist) return res.status(400).send("email already exists");

    const { originalname: name, size, filename: key } = req.file;
    const documents = new File({
      name,
      size,
      key,
    });

    try {
      const savedDocuments = await documents.save();
      const inscription = new Inscriptions({
        name: req.body.name,
        email: req.body.email,
        phone: req.body.phone,
        documents: savedDocuments,
      });
      try {
        const savedInscription = await inscription.save();
        res.send({ inscription: savedInscription._id });
      } catch (err) {
        res.status(400).send(err);
      }
    } catch (err) {
      res.status(400).send(err);
    }
  },

  async update(req, res) {
    const { error } = inscriptionsValidation(req.body);
    if (error) return res.status(400).send(error.details[0].message);

    const emailExist = await Inscriptions.findOne({ email: req.body.email });
    if (emailExist && emailExist._id != req.params.id)
      return res.status(400).send("email already exists");

    try {
      await Inscriptions.updateOne(
        { _id: req.params.id },
        {
          name: req.body.name,
          email: req.body.email,
          phone: req.body.phone,
        }
      );
      res.status(200).send("Success");
    } catch (err) {
      res.status(500).send(err);
    }
  },

  async destroy(req, res) {
    //delete documents from server
    const inscription = await Inscriptions.findOne({
      _id: req.params.id,
    }).populate("documents");
    const filename = inscription.documents.key;
    fs.unlink(`tmp/documents/${filename}`, (err) => {
      if (err) console.log(err);
    });

    //delete documents from db
    try {
      await File.deleteOne({ _id: inscription.documents._id });
    } catch (err) {
      console.log(err);
    }

    //delete inscription
    try {
      const removedInscription = await Inscriptions.deleteOne({
        _id: req.params.id,
      });
      res.json({ inscription: removedInscription });
    } catch (err) {
      res.json({ message: err });
    }
  },

  async updateInscription(req, res) {
    try {
      await Inscriptions.updateOne(
        { _id: req.params.id },
        {
          accepted: req.body.accepted,
        }
      );
      res.status(200).send("Success");
    } catch (err) {
      res.status(500).send(err);
    }
  },
};
