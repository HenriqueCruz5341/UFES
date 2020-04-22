import React, { useState } from "react";
import { MDBContainer, MDBRow, MDBCol, MDBBtn } from "mdbreact";
import api from "../../../../../services/api";
import InputMask from "react-input-mask";
import { Link } from "react-router-dom";

function RegisterAdmin() {
  const [name, setName] = useState("");
  const [email, setEmail] = useState("");
  const [phone, setPhone] = useState("");
  const [password, setPassword] = useState("");
  const [repeatPassword, setRepeatPassword] = useState("");
  const [validEmailForm, setValidEmailForm] = useState("");
  const [validPassword, setValidPassword] = useState(false);
  const [validPasswordForm, setValidPasswordForm] = useState("");
  const [validPasswordDiv, setValidPasswordDiv] = useState(<div></div>);

  function verifySamePassword() {
    if (password !== repeatPassword) {
      setValidPasswordForm("is-invalid");
      setValidPassword(false);
      setValidPasswordDiv(
        <div className="invalid-feedback">As senhas devem ser iguais</div>
      );
    } else if (password.length < 6) {
      setValidPasswordForm("is-invalid");
      setValidPassword(false);
      setValidPasswordDiv(
        <div className="invalid-feedback">
          A senha deve ter pelo menos 6 digitos
        </div>
      );
    } else {
      setValidPasswordForm("is-valid");
      setValidPassword(true);
      setValidPasswordDiv(<div className="valid-feedback">Ótimo!</div>);
    }
  }

  async function handleAddAdmin(e) {
    e.preventDefault();
    console.log(name, email, password, phone);
    try {
      await api.post("/api/user", {
        name,
        email,
        password,
        phone,
        admin: true,
      });
    } catch (error) {
      console.log(error.response);
      setValidEmailForm("is-invalid");
    }
  }

  return (
    <MDBContainer style={{ paddingTop: "150px" }}>
      <Link to="/adminsList">
        <MDBBtn color="primary">Voltar</MDBBtn>
      </Link>
      <form onSubmit={handleAddAdmin}>
        <MDBRow>
          <MDBCol sm="12">
            <h3 style={{ color: "black" }}>Cadastro de Administradores</h3>
          </MDBCol>
        </MDBRow>
        <MDBRow>
          <MDBCol sm="7">
            <label htmlFor="iname" className="grey-text">
              Nome Completo
            </label>
            <input
              id="iname"
              type="text"
              value={name}
              className="form-control"
              onChange={(e) => setName(e.target.value)}
              required
            />
          </MDBCol>
          <MDBCol sm="5">
            <label htmlFor="iphone" className="grey-text">
              Telefone
            </label>
            <InputMask
              mask="(99) 99999-9999"
              id="iphone"
              className="form-control"
              value={phone}
              onChange={(e) => setPhone(e.target.value)}
              required
              minLength="15"
            />
          </MDBCol>
        </MDBRow>
        <MDBRow>
          <MDBCol>
            <label htmlFor="iemail" className="grey-text">
              E-mail
            </label>
            <input
              id="iemail"
              className={"form-control " + validEmailForm}
              type="email"
              value={email}
              onChange={(e) => setEmail(e.target.value)}
              required
            />
          </MDBCol>
        </MDBRow>
        <MDBRow>
          <MDBCol sm="6">
            <label htmlFor="ipassword" className="grey-text">
              Senha
            </label>
            <input
              id="ipassword"
              type="password"
              className={`form-control ${validPasswordForm}`}
              value={password}
              onChange={(e) => setPassword(e.target.value)}
              onBlur={(e) => verifySamePassword(repeatPassword)}
              required
            />
            {validPasswordDiv}
          </MDBCol>
          <MDBCol sm="6">
            <label htmlFor="irepeatpassword" className="grey-text">
              Repita a senha
            </label>
            <input
              id="irepeatpassword"
              type="password"
              className={`form-control ${validPasswordForm}`}
              value={repeatPassword}
              onChange={(e) => setRepeatPassword(e.target.value)}
              onBlur={(e) => verifySamePassword(repeatPassword)}
              required
            />
            {validPasswordDiv}
          </MDBCol>
        </MDBRow>
        <MDBRow>
          <MDBCol>
            <MDBBtn color="blue" disabled={!validPassword} type="submit">
              Confirmar
            </MDBBtn>
          </MDBCol>
        </MDBRow>
      </form>
    </MDBContainer>
  );
}

export default RegisterAdmin;
