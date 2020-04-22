import React, { useState, useEffect } from "react";
import {
  MDBContainer,
  MDBTable,
  MDBTableBody,
  MDBTableHead,
  MDBBtn
} from "mdbreact";
import { Link } from "react-router-dom";
import api from "../../../../../services/api";

function InspecStudents(props) {
  const [student, setStudent] = useState();
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    async function getStudent() {
      let response;
      let idStudent = props.history.location.pathname.split("/")[3];
      const token = localStorage.getItem("LOGINJACEE_TOKEN");
      try {
        response = await api.get(`/api/student/${idStudent}`, {
          headers: { "auth-token": token }
        });
        setStudent({ ...response.data.student });
        setLoading(false);
      } catch (err) {
        console.log(err.response);
      }
    }
    getStudent(); // eslint-disable-next-line
  }, [props]);

  return (
    <MDBContainer style={{ paddingTop: "150px" }} className="tableInspecEvent">
      {loading ? (
        <div className="spinner-border" role="status"></div>
      ) : (
        <>
          <Link to="/studentsAdmin">
            <MDBBtn color="primary">Voltar</MDBBtn>
          </Link>
          <MDBTable responsive>
            <MDBTableHead>
              <tr>
                <th colSpan="2">{student.person.name}</th>
              </tr>
            </MDBTableHead>
            <MDBTableBody>
              <tr>
                <td>ID_Studante:</td>
                <td>{student._id}</td>
              </tr>
              <tr>
                <td>CPF:</td>
                <td>{student.cpf}</td>
              </tr>
              <tr>
                <td>Pagamento:</td>
                <td>{student.paid ? "Confirmado" : "Aguardando"}</td>
              </tr>
              <tr>
                <td>Horas cumpridas:</td>
                <td>{student.hours}</td>
              </tr>
              <tr>
                <td>Instituição:</td>
                <td>{student.institution}</td>
              </tr>
              <tr>
                <td>Course:</td>
                <td>{student.course}</td>
              </tr>
              <tr>
                <td>ID_Pessoa:</td>
                <td>{student.person._id}</td>
              </tr>
              <tr>
                <td>E-mail:</td>
                <td>{student.person.email}</td>
              </tr>
              <tr>
                <td>Telefone:</td>
                <td>{student.person.phone}</td>
              </tr>
              <tr>
                <td>Data inscrição:</td>
                <td>{student.date}</td>
              </tr>
            </MDBTableBody>
          </MDBTable>
        </>
      )}
    </MDBContainer>
  );
}

export default InspecStudents;
