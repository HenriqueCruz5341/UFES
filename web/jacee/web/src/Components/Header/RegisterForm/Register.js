import React, { useState } from "react";
import { MDBContainer } from "mdbreact";
import "../../../services/api";
import api from "../../../services/api";
import "./register.css";
import InputMask from "react-input-mask";
import validarCpf from "validar-cpf";
import { useToasts } from "react-toast-notifications";
import { MDBBtnS } from "../../../globalStyle";

function Register(props) {
  const [email, setEmail] = useState("");
  const [password, setPassword] = useState("");
  const [repeatPassword, setRepeatPassword] = useState("");
  const [name, setName] = useState("");
  const [cpf, setCpf] = useState("");
  const [phone, setPhone] = useState("");
  const [institution, setInstitution] = useState("");
  const [course, setCourse] = useState("");
  const [validEmailForm, setValidEmailForm] = useState("");
  const [validPassword, setValidPassword] = useState(false);
  const [validPasswordForm, setValidPasswordForm] = useState("");
  const [validPasswordDiv, setValidPasswordDiv] = useState(<div></div>);
  const [validCpf, setValidCpf] = useState(false);
  const [validCpfForm, setValidCpfForm] = useState("");
  const { addToast } = useToasts();

  async function handleAddStudent(e) {
    e.preventDefault();
    try {
      await api.post("/api/student", {
        cpf,
        paid: false,
        institution,
        course,
        name,
        email,
        password,
        phone,
      });
      console.log(email, password);
      addToast("Cadastro realizado com sucesso!", { appearance: "success" });
      // toggle();
    } catch (error) {
      addToast(error.response.data, { appearance: "error" });
      setValidEmailForm("is-invalid");
    }
  }

  function verifyCpf() {
    if (!validarCpf(cpf)) {
      setValidCpf(false);
      setValidCpfForm("is-invalid");
    } else {
      setValidCpf(true);
      setValidCpfForm("is-valid");
    }
  }

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

  return (
    <form onSubmit={handleAddStudent}>
      <MDBContainer className="formCadastroEstudante">
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

        <label htmlFor="iname" className="grey-text">
          Nome completo
        </label>
        <input
          id="iname"
          className="form-control"
          value={name}
          onChange={(e) => setName(e.target.value)}
          required
        />

        <label htmlFor="icpf" className="grey-text">
          CPF
        </label>
        <InputMask
          mask="999.999.999-99"
          id="icpf"
          className={`form-control ${validCpfForm}`}
          value={cpf}
          onChange={(e) => setCpf(e.target.value)}
          onBlur={(e) => verifyCpf()}
          required
          minLength="14"
        />

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

        <label htmlFor="iinstitution" className="grey-text">
          Instiuição
        </label>
        <input
          id="iinstitution"
          className="form-control"
          value={institution}
          onChange={(e) => setInstitution(e.target.value)}
          required
        />

        <label htmlFor="icourse" className="grey-text">
          Curso
        </label>
        <input
          id="icourse"
          className="form-control"
          value={course}
          onChange={(e) => setCourse(e.target.value)}
          required
        />

        <div className="text-center mt-4 buttonRegisterStudent">
          <MDBBtnS
            btncolor="rgb(19, 156, 217)"
            disabled={!(validPassword && validCpf)}
            type="submit"
          >
            Confirmar
          </MDBBtnS>
        </div>
      </MDBContainer>
    </form>
  );
}

export default Register;
