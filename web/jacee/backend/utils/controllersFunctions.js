const bcrypt = require("bcryptjs")
const nodemailer = require("nodemailer")
const Person = require("../models/Person")

function randomString() {
  var text = "";
  var possible = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

  for (var i = 0; i < 8; i++)
    text += possible.charAt(Math.floor(Math.random() * possible.length));

  return text;
}


async function hashPassword(password) {
  const salt = await bcrypt.genSalt(10)
  const hashedPassword = await bcrypt.hash(password, salt)
  return hashedPassword
}

async function createTransporter(transporter) {
  transporter = await nodemailer.createTransport({
    host: "smtp.gmail.com",
    port: 465,
    secure: true,
    auth: {
      user: process.env.EMAIL,
      pass: process.env.EMAIL_PASSWORD
    }

  })
}

function updatePassword(email, hashedPassword) {
  Person.updateOne(
    { email: email },
    { password: hashedPassword }
  ).then((updatedPassword) => {
    console.log(updatedPassword)
  }).catch((err) => {
    console.log(err)
  })

}
async function sendNewPasswordMail(req, res, transporter, newPassword) {
  const message = await transporter.sendMail({
    from: process.env.EMAIL,
    to: req.body.email,
    subject: "Pedido de alteração de senha - Jacee",
    html: `Olá recebemos um pedido de alteração de senha, sua nova senha temporária é ${newPassword}.<br>
            Clique nesse <a href = "localhost:3000"> link </a> para alterar sua senha.`
  })
  res.json({ message })
}


module.exports.randomString = randomString
module.exports.hashPassword = hashPassword
module.exports.createTransporter = createTransporter
module.exports.updatePassword = updatePassword
module.exports.sendNewPasswordMail = sendNewPasswordMail