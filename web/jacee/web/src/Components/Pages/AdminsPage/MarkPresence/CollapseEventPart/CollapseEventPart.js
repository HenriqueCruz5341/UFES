import React, { useState } from "react";
import {
  MDBBtn,
  MDBCollapse,
  MDBIcon,
  MDBContainer,
  MDBTable,
  MDBTableBody,
  MDBTableHead,
} from "mdbreact";
import "./collapseEventPart.css";
import api from "../../../../../services/api";

function CollapseEventPart(props) {
  let { students, children, part, people } = props;
  const [collapseID, setCollapseID] = useState("");
  const [icon, setIcon] = useState(<MDBIcon icon="angle-down" />);
  const columns = [
    {
      label: "Nome",
      field: "name",
      sort: "asc",
    },
    {
      label: "Situação",
      field: "situation",
      sort: "asc",
    },
  ];
  const [studentsPresent, setStudentsPresent] = useState([...part.students]);

  const toggleCollapse = (collapseID) => () => {
    setCollapseID((prevState) => (prevState !== collapseID ? collapseID : ""));
  };

  function dateConvert(dateI) {
    let dateC = dateI.slice(8, 10) + "/" + dateI.slice(5, 7);

    return dateC;
  }

  function timeConvert(timeI) {
    let timeC = timeI.slice(11, 16);

    return timeC;
  }

  function handleMarkPresence() {
    const token = localStorage.getItem("LOGINJACEE_TOKEN");
    studentsPresent.forEach(async (student) => {
      if (part.students.indexOf(student._id) === -1) {
        try {
          await api.patch(
            `/api/event/markPresence/${part._id}`,
            { idStudent: student },
            { headers: { "auth-token": token } }
          );
        } catch (err) {
          console.log(err.response);
        }
      }
    });
  }

  const typeButton = (student) => {
    if (studentsPresent.indexOf(student._id) === -1) {
      return (
        <MDBBtn
          color="success"
          size="sm"
          onClick={() => setStudentsPresent((prev) => [...prev, student._id])}
        >
          <MDBIcon size="lg" far icon="check-circle" />
        </MDBBtn>
      );
    } else {
      return (
        <MDBBtn
          color="danger"
          size="sm"
          onClick={
            part.students.indexOf(student._id) === -1
              ? () =>
                  setStudentsPresent((prev) => [
                    ...prev.filter((elem) => elem !== student._id),
                  ])
              : () => {}
          }
        >
          <MDBIcon size="lg" icon="ban" />
        </MDBBtn>
      );
    }
  };

  const populateRows = () => {
    let rs = [];
    for (let i = 0; i < students.length; i++) {
      rs.push({
        name: people[i].name,
        situation: typeButton(students[i]),
      });
    }
    return [...rs];
  };

  return (
    <>
      <MDBBtn
        color="mdb-color"
        onClick={toggleCollapse("basicCollapse")}
        className="botaoCollapse"
      >
        <div className="conteudoBotao">
          <strong>
            {dateConvert(children) + " | " + timeConvert(children)}
          </strong>
          <div className="iconesBotao">{icon}</div>
        </div>
      </MDBBtn>
      <MDBCollapse
        className="conteudoCollapse"
        onOpened={() => setIcon(<MDBIcon icon="angle-up" />)}
        onClosed={() => setIcon(<MDBIcon icon="angle-down" />)}
        id="basicCollapse"
        isOpen={collapseID}
      >
        <MDBContainer>
          <MDBTable className="collapseEventPartTable" responsive bordered>
            <MDBTableHead columns={columns} />
            <MDBTableBody rows={populateRows()} />
          </MDBTable>
          <div>
            <MDBBtn onClick={() => handleMarkPresence()}>Confirmar</MDBBtn>
          </div>
        </MDBContainer>
      </MDBCollapse>
    </>
  );
}

export default CollapseEventPart;
