const jwt = require("jsonwebtoken");

module.exports = function (req, res, next) {
  //o token deve ser passado como um bearer token

  if (!req.headers.authorization) {
    return res.status(401).send("Access Denied");
  }
  const [, token] = req.headers.authorization.split(" ");
  try {
    jwt.verify(token, process.env.TOKEN_SECRET);
    next();
  } catch (err) {
    res.status(400).send("Invalid Token");
  }
};
