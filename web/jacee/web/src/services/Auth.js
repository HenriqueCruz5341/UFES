import jsonWebTokenService from "jsonwebtoken";

function isAuth() {
  const token = localStorage.getItem("LOGINJACEE_TOKEN");
  if (token != null) {
    return jsonWebTokenService.decode(token).admin;
  }
  return null;
}

export default isAuth;
