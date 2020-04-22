const Joi = require("@hapi/joi");

const inscriptionsValidation = (data) => {
  const schema = Joi.object({
    name: Joi.string().min(2).required(),
    email: Joi.string().min(6).required().email(),
    phone: Joi.string().min(11).max(15),
    documents: Joi.object(),
  });
  return schema.validate(data);
};

const newsValidation = (data) => {
  const schema = Joi.object({
    title: Joi.string().min(5).required(),
    images: Joi.array(),
    text: Joi.string().min(5).required(),
  });
  return schema.validate(data);
};

module.exports.inscriptionsValidation = inscriptionsValidation;
module.exports.newsValidation = newsValidation;
