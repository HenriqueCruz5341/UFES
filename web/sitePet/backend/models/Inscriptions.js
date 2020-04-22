const mongoose = require("mongoose");
const inscriptionsSchema = mongoose.Schema({
  name: {
    type: String,
    require: true,
  },
  email: {
    type: String,
    require: true,
  },
  phone: {
    type: String,
    max: 15,
    min: 11,
    require: true,
  },
  documents: {
    type: mongoose.Schema.Types.ObjectId,
    ref: "File",
    required: true,
  },
  accepted: {
    type: Boolean,
    default: false,
  },
});

module.exports = mongoose.model("Inscriptions", inscriptionsSchema);
