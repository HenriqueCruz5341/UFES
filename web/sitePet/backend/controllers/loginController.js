const jwt = require("jsonwebtoken");
const bcrypt = require("bcryptjs");

module.exports = {
  async login(req, res) {
    //Fazer as buscas em petianos para confirmar credenciais
    //https://www.youtube.com/watch?v=T_PGIyEh0dg
    //usar basic autentication para que as infos venham no header

    const [, hash] = req.headers.authorization.split(" ");
    const [email, password] = Buffer.from(hash, "base64").toString().split(":");

    // try {
    // const user = await Petianos.findOne({email});
    //   if (!user) return res.status(401).send("Email not found");

    //   const validPass = await bcrypt.compare(password, user.password);
    //   if (!validPass) return res.status(401).send("Invalid password");

    const token = jwt.sign({ _id: 123456 }, process.env.TOKEN_SECRET);

    res.send({ token });
    // } catch (err) {
    //   res.send(err);
    // }
  },
};
