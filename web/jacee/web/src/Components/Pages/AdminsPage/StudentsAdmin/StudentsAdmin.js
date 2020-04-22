import React, { useState, useEffect } from "react";
import { MDBContainer, MDBDataTable, MDBBtn, MDBIcon } from "mdbreact";
import api from "../../../../services/api";
import { Link } from "react-router-dom";
import ModalDelete from "../ModalDelete/ModalDelete";

function StudentsAdmin() {
  const columns = [
    {
      label: "CPF",
      field: "cpf",
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
      label: "Horas",
      field: "hours",
      sort: "asc"
    },
    {
      label: "Pago",
      field: "paid",
      sort: "asc"
    },
    {
      label: "Ações",
      field: "action"
    }
  ];
  const [rows, setRows] = useState([]);
  const [modal, setModal] = useState(false);
  const [selectedStudent, setSelectedStudent] = useState({});

  function toggle(student) {
    setModal(!modal);
    setSelectedStudent(student);
  }

  async function paymentUpdate(student) {
    const token = localStorage.getItem("LOGINJACEE_TOKEN");
    try {
      await api.patch(
        "/api/student/paymentUpdate",
        { idStudent: student._id, paid: !student.paid },
        { headers: { "auth-token": token } }
      );
      setRows([...rows]);
    } catch (err) {
      console.log(err.response);
    }
  }

  async function loadStudents() {
    let tempStudents = await api.get("/api/student/");
    let rs = [];
    tempStudents.data.students.map(student => {
      return (rs = [
        ...rs,
        {
          id: student._id,
          name: student.person.name,
          email: student.person.email,
          cpf: student.cpf,
          hours: student.hours,
          paid: student.paid ? "Sim" : "Não",
          action: (
            <>
              <Link to={"/studentsAdmin/inspect/" + student._id}>
                <MDBBtn color="primary" size="sm">
                  <MDBIcon size="lg" icon="eye" />
                </MDBBtn>
              </Link>
              <MDBBtn
                onClick={() => paymentUpdate(student)}
                color="success"
                size="sm"
              >
                <MDBIcon far size="lg" icon="money-bill-alt" />
              </MDBBtn>
              <MDBBtn onClick={() => toggle(student)} color="danger" size="sm">
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
    loadStudents();
    // eslint-disable-next-line
  }, [rows]);

  return (
    <MDBContainer style={{ paddingTop: "150px" }}>
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
        load={loadStudents}
        item={selectedStudent}
        toggle={toggle}
        stateModalDelete={modal}
        type="student"
      />
    </MDBContainer>
  );
}

export default StudentsAdmin;
