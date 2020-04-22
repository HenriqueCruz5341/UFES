import React from "react";
import { MDBModal, MDBModalBody, MDBModalHeader } from "mdbreact";
import Register from "../RegisterForm/Register";

function ModalRegisterStudent(props) {
  let { toggleModalRegisterStudent, stateModal } = props;

  return (
    <MDBModal
      isOpen={stateModal}
      toggle={toggleModalRegisterStudent}
      fullHeight
      position="right"
    >
      <MDBModalHeader toggle={toggleModalRegisterStudent}>
        Cadastre-se
      </MDBModalHeader>
      <MDBModalBody>
        <Register toggle={toggleModalRegisterStudent} />
      </MDBModalBody>
    </MDBModal>
  );
}

export default ModalRegisterStudent;
