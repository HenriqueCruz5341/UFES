import React, { useEffect, useState } from "react";
import {
  MDBBtn,
  MDBModal,
  MDBModalBody,
  MDBModalHeader,
  MDBModalFooter
} from "mdbreact";
import api from "../../../../services/api";

function ModalDelete(props) {
  let { toggle, stateModalDelete, item, load, type } = props;
  const [name, setName] = useState();

  useEffect(() => {
    if (item._id) {
      if (type === "student") setName(item.person.name);
      if (type === "event") setName(item.title);
      if (type === "user") setName(item.name);
    }
  }, [item, type]);

  async function deletItem() {
    const token = localStorage.getItem("LOGINJACEE_TOKEN");
    try {
      await api.delete(`/api/${type}/${item._id}`, {
        headers: { "auth-token": token }
      });
      load();
      toggle(item);
    } catch (err) {
      console.log(err.response);
    }
  }

  return (
    <MDBModal
      isOpen={stateModalDelete}
      toggle={() => toggle(item)}
      fade={stateModalDelete}
      centered
    >
      <MDBModalHeader toggle={() => toggle(item)}>Deletando</MDBModalHeader>
      <MDBModalBody>
        Tem certeza que deseja deletar <strong>{name}</strong>?
      </MDBModalBody>
      <MDBModalFooter>
        <MDBBtn size="sm" color="primary" onClick={() => toggle(item)}>
          Cancelar
        </MDBBtn>
        <MDBBtn size="sm" color="danger" onClick={deletItem}>
          Sim
        </MDBBtn>
      </MDBModalFooter>
    </MDBModal>
  );
}

export default ModalDelete;
