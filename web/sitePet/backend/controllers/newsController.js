const News = require("../models/News");
const { newsValidation } = require("../utils/validation");

module.exports = {
  async index(req, res) {
    const news = await News.find();
    res.json({ news });
  },

  async show(req, res) {
    const news = await News.findOne({ _id: req.params.id });
    res.json({ new: news });
  },

  async store(req, res) {
    const { error } = newsValidation(req.body);
    if (error) return res.status(400).send(error.details[0].message);

    const news = new News({
      title: req.body.title,
      images: req.body.images,
      text: req.body.text,
    });
    try {
      const savedNew = await news.save();
      res.send({ new: savedNew._id });
    } catch (err) {
      res.status(400).send(err);
    }
  },

  async destroy(req, res) {
    try {
      const removedNew = await News.deleteOne({ _id: req.params.id });
      res.json({
        new: removedNew,
      });
    } catch (err) {
      res.json({ message: err });
    }
  },

  async update(req, res) {
    const { error } = newsValidation(req.body);
    if (error) return res.status(400).send(error.details[0].message);

    try {
      const updatedNew = await News.updateOne(
        { _id: req.params.id },
        {
          title: req.body.title,
          images: req.body.images,
          text: req.body.text,
        }
      );
      res.status(200).send({ new: updatedNew });
    } catch (err) {
      res.status(500).send(err);
    }
  },
};
