import React, { useState } from "react";
import {
  MDBModal,
  MDBModalBody,
  MDBModalHeader,
  MDBModalFooter,
  MDBContainer,
  MDBRow,
  MDBCol,
} from "mdbreact";
import api from "../../../../../services/api";
import { useToasts } from "react-toast-notifications";
import { MDBBtnS } from "../../../../../globalStyle";

function ModalChangePassword(props) {
  let { toggle, stateModal } = props;
  const [email, setEmail] = useState("");
  const [oldPass, setOldPass] = useState("");
  const [newPass, setNewPass] = useState("");
  const [repeatNewPass, setRepeatNewPass] = useState("");
  const [validPassword, setValidPassword] = useState(false);
  const [validPasswordForm, setValidPasswordForm] = useState("");
  const [validPasswordDiv, setValidPasswordDiv] = useState(<div></div>);
  const { addToast } = useToasts();

  async function handleChangePassword(e) {
    e.preventDefault();

    try {
      await api.put("/api/login/", {
        oldPassword: oldPass,
        newPassword: newPass,
        email,
      });
      addToast("Senha alterada com sucesso!", { appearance: "success" });
      toggle();
    } catch (err) {
      addToast(err.response.data, { appearance: "error" });
      toggle();
    }
  }

  function verifySamePassword() {
    if (newPass !== repeatNewPass) {
      setValidPasswordForm("is-invalid");
      setValidPassword(false);
      setValidPasswordDiv(
        <div className="invalid-feedback">As senhas devem ser iguais</div>
      );
    } else if (newPass.length < 6) {
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
    <MDBModal
      isOpen={stateModal}
      toggle={() => toggle()}
      fade={stateModal}
      centered
    >
      <MDBModalHeader toggle={() => toggle()}>Mudança de senha</MDBModalHeader>
      <form onSubmit={handleChangePassword}>
        <MDBModalBody>
          <MDBContainer>
            <MDBRow>
              <MDBCol sm="12">
                <label htmlFor="iemailchange" className="grey-text">
                  E-mail
                </label>
                <input
                  className="form-control"
                  type="email"
                  name="email"
                  id="iemailchange"
                  value={email}
                  onChange={(e) => setEmail(e.target.value)}
                  required
                />
              </MDBCol>
            </MDBRow>
            <MDBRow>
              <MDBCol sm="12">
                <label htmlFor="ioldpass" className="grey-text">
                  Senha Antiga
                </label>
                <input
                  id="ioldpass"
                  type="password"
                  className="form-control"
                  value={oldPass}
                  onChange={(e) => setOldPass(e.target.value)}
                  required
                />
              </MDBCol>
            </MDBRow>
            <MDBRow>
              <MDBCol sm="12">
                <label htmlFor="inewpass" className="grey-text">
                  Nova senha
                </label>
                <input
                  id="inewpass"
                  type="password"
                  className={`form-control ${validPasswordForm}`}
                  value={newPass}
                  onChange={(e) => setNewPass(e.target.value)}
                  onBlur={verifySamePassword}
                  required
                />
                {validPasswordDiv}
              </MDBCol>
            </MDBRow>
            <MDBRow>
              <MDBCol sm="12">
                <label htmlFor="irepeatnewpass" className="grey-text">
                  Repita a nova senha
                </label>
                <input
                  id="irepeatnewpass"
                  type="password"
                  className={`form-control ${validPasswordForm}`}
                  value={repeatNewPass}
                  onChange={(e) => setRepeatNewPass(e.target.value)}
                  onBlur={verifySamePassword}
                  required
                />
                {validPasswordDiv}
              </MDBCol>
            </MDBRow>
          </MDBContainer>
        </MDBModalBody>
        <MDBModalFooter>
          <MDBBtnS
            btncolor="rgb(247, 180, 5)"
            type="reset"
            size="sm"
            onClick={() => toggle()}
          >
            Cancelar
          </MDBBtnS>
          <MDBBtnS
            btncolor="rgb(19, 156, 217)"
            type="submit"
            size="sm"
            onClick={handleChangePassword}
            disabled={!validPassword}
          >
            Confirmar
          </MDBBtnS>
        </MDBModalFooter>
      </form>
    </MDBModal>
  );
}

export default ModalChangePassword;
