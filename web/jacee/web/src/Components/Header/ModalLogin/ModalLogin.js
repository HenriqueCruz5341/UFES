import React from "react";
import { MDBModal, MDBModalBody, MDBModalHeader } from "mdbreact";
import Login from "../LoginForm/Login";

function ModalLogin(props) {
  let { toggleModalLogin, stateModal } = props;

  return (
    <MDBModal
      isOpen={stateModal}
      toggle={toggleModalLogin}
      fullHeight
      position="right"
    >
      <MDBModalHeader toggle={toggleModalLogin}>Login</MDBModalHeader>
      <MDBModalBody>
        <Login toggle={toggleModalLogin} />
      </MDBModalBody>
    </MDBModal>
  );
}

export default ModalLogin;
