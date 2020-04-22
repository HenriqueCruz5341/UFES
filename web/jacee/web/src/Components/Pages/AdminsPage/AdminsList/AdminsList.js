import React, { useState, useEffect } from "react";
import { MDBContainer, MDBDataTable, MDBBtn, MDBIcon } from "mdbreact";
import api from "../../../../services/api";
import { Link } from "react-router-dom";
import ModalDelete from "../ModalDelete/ModalDelete";

function AdminsList() {
  const columns = [
    {
      label: "ID",
      field: "id",
      sort: "asc"
    },
    {
      label: "Nome",
      field: "name",
      sort: "asc"
    },
    {
      label: "E-mail",
      field: "email",
      sort: "asc"
    },
    {
      label: "Telefone",
      field: "phone",
      sort: "asc"
    },
    {
      label: "Ações",
      field: "action"
    }
  ];
  const [rows, setRows] = useState([]);
  const [modal, setModal] = useState(false);
  const [selectedPerson, setSelectedPerson] = useState({});

  function toggle(person) {
    setModal(!modal);
    setSelectedPerson(person);
  }

  async function loadPeople() {
    let tempPeople = await api.get("/api/user/");
    let rs = [];
    tempPeople.data.persons.forEach(person => {
      if (person.admin)
        return (rs = [
          ...rs,
          {
            id: person._id,
            name: person.name,
            email: person.email,
            phone: person.phone,
            action: (
              <>
                <MDBBtn onClick={() => toggle(person)} color="danger" size="sm">
                  <MDBIcon size="lg" icon="trash" />
                </MDBBtn>
              </>
            )
          }
        ]);
    });
    setRows([...rs]);
  }

  useEffect(() => {
    loadPeople();
    // eslint-disable-next-line
  }, [rows]);

  return (
    <MDBContainer style={{ paddingTop: "150px" }}>
      <Link to="/adminsList/register">
        <MDBBtn color="primary">Cadastrar novo Administrador</MDBBtn>
      </Link>
      <MDBDataTable
        className="tableEventsAdmin"
        striped
        responsive
        displayEntries={false}
        bordered
        hover
        noBottomColumns
        data={{ columns, rows }}
      />
      <ModalDelete
        load={loadPeople}
        item={selectedPerson}
        toggle={toggle}
        stateModalDelete={modal}
        type="user"
      />
    </MDBContainer>
  );
}

export default AdminsList;
