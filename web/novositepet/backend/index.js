const express = require("express");
const mongoose = require("mongoose");
require("dotenv").config();
const cors = require("cors");

const app = express();

const newsRoute = require("./routes/news");
const inscriptionsRoute = require("./routes/inscriptions");
const fileRoute = require("./routes/file");

mongoose.connect(
  process.env.DB_CONNECT,
  { useNewUrlParser: true, useUnifiedTopology: true },
  () => console.log("Conneted to db!")
);

app.use(express.json());
app.use(cors());

app.use("/api/news", newsRoute);
app.use("/api/inscriptions", inscriptionsRoute);
app.use("/api/file", fileRoute);

app.listen(3333, () => console.log("Server running"));
