import React, { useState } from "react";
import { MDBContainer, MDBTabPane, MDBTabContent } from "mdbreact";
import "../../../services/api";
import api from "../../../services/api";
import { useToasts } from "react-toast-notifications";
import { ForgPass } from "./style";
import { MDBBtnS } from "../../../globalStyle";

function Login(props) {
  const [email, setEmail] = useState("");
  const [emailForgot, setEmailForgot] = useState("");
  const [password, setPassword] = useState("");
  const [validLogin, setValidLogin] = useState("");
  const [validEmailForgot, setValidEmailForgot] = useState("");
  let { toggle } = props;
  const { addToast } = useToasts();
  const [activeItem, setActiveItem] = useState("1");

  const togglePanel = (tab) => (e) => {
    if (activeItem !== tab) setActiveItem(tab);
  };

  async function handleForgotPassword(e) {
    e.preventDefault();

    try {
      await api.patch("/api/login/", { email: emailForgot });
      addToast("Nova senha enviada com sucesso!", {
        appearance: "success",
      });
      setValidEmailForgot("");
    } catch (err) {
      setValidEmailForgot("is-invalid");
      addToast(err.response.data, { appearance: "error" });
    }
  }

  async function handleLogin(e) {
    e.preventDefault();
    let responseLogin;

    try {
      responseLogin = await api.post("/api/login/", { email, password });
      setValidLogin("");
      localStorage.setItem("LOGINJACEE_TOKEN", responseLogin.data);
      toggle();
    } catch (err) {
      // console.log(err.response);
      setValidLogin("is-invalid");
      addToast(err.response.data, { appearance: "error" });
    }
  }

  return (
    <MDBTabContent activeItem={activeItem}>
      <MDBTabPane tabId="1" role="tabpanel">
        <form onSubmit={handleLogin}>
          <MDBContainer>
            <label htmlFor="iemail" className="grey-text">
              E-mail
            </label>
            <input
              id="iemail"
              className={`form-control ${validLogin}`}
              type="email"
              value={email}
              onChange={(e) => setEmail(e.target.value)}
              required
            />

            <label htmlFor="ipassword" className="grey-text">
              Senha
            </label>
            <input
              id="ipassword"
              type="password"
              className={`form-control ${validLogin}`}
              value={password}
              onChange={(e) => setPassword(e.target.value)}
              required
            />
            <div>
              <ForgPass onClick={togglePanel("2")}>
                Esqueci minha senha.
              </ForgPass>
            </div>
            <div className="text-center mt-4">
              <MDBBtnS btncolor="rgb(19, 156, 217)" type="submit">
                Confirmar
              </MDBBtnS>
            </div>
          </MDBContainer>
        </form>
      </MDBTabPane>
      <MDBTabPane tabId="2" role="tabpanel">
        <form onSubmit={handleForgotPassword}>
          <MDBContainer>
            Iremos enviar um e-mail com uma nova senha para você.
            <br />
            <label htmlFor="iemailforgotpass" className="grey-text">
              E-mail
            </label>
            <input
              id="iemailforgotpass"
              className={`form-control ${validEmailForgot}`}
              type="email"
              value={emailForgot}
              onChange={(e) => setEmailForgot(e.target.value)}
              required
            />
            <div>
              <ForgPass onClick={togglePanel("1")}>Voltar</ForgPass>
            </div>
            <div className="text-center mt-4">
              <MDBBtnS btncolor="rgb(19, 156, 217)" type="submit">
                Confirmar
              </MDBBtnS>
            </div>
          </MDBContainer>
        </form>
      </MDBTabPane>
    </MDBTabContent>
  );
}

export default Login;
