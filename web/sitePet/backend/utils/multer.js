const multer = require("multer");
const path = require("path");
const crypto = require("crypto");

const multerConfig = (type) => {
  let folder, allowedMimes;

  if (type === "zip") {
    folder = "inscriptions";
    allowedMimes = ["application/zip"];
  } else if (type === "pdf") {
    folder = "documents";
    allowedMimes = ["application/pdf"];
  }

  return {
    dest: path.resolve(__dirname, "..", "tmp", folder),
    storage: multer.diskStorage({
      destination: (req, file, cb) => {
        cb(null, path.resolve(__dirname, "..", "tmp", folder));
      },
      filename: (req, file, cb) => {
        crypto.randomBytes(16, (err, hash) => {
          if (err) cb(err);

          const fileName = `${hash.toString("hex")}-${file.originalname}`;

          cb(null, fileName);
        });
      },
    }),
    limits: {
      fileSize: 5 * 1024 * 1024,
    },
    fileFilter: (req, file, cb) => {
      if (allowedMimes.includes(file.mimetype)) {
        cb(null, true);
      } else {
        cb(new Error("Invalid file type."));
      }
    },
  };
};

module.exports.multerConfig = multerConfig;
