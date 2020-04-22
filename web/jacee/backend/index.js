const express = require ("express")
const dotenv = require("dotenv")
const mongoose = require("mongoose")
const cors = require('cors')

const app = express()

// import routes
const personRoute = require("./routes/person")
const loginRoute = require("./routes/login")
const studentRoute = require("./routes/student")
const eventRoute = require("./routes/event")
dotenv.config()

// connect to db
mongoose.connect(process.env.DB_CONNECT,{ useUnifiedTopology: true,useNewUrlParser: true, useFindAndModify: false },()=>{
    console.log("conneted to db!")
} )


//midllewares
app.use(express.json())
app.use(cors())
//routes middlewares

app.use("/api/login", loginRoute)
app.use("/api/user", personRoute)
app.use("/api/student", studentRoute)
app.use("/api/event", eventRoute)




app.listen(3333, ()=> console.log("Server running"))