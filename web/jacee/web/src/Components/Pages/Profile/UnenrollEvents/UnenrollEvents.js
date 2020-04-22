import React, { useState } from "react";
import { MDBListGroup, MDBCol, MDBRow } from "mdbreact";
import { MDBListGroupItemS, MDBIconS } from "./style";
import { useStudent } from "../../../../Contexts/Student";
import ModalUnenrollEvent from "../ModalUnenrollEvent/ModalUnenrollEvent";

const sColForm = { color: "black", alignItems: "flex-start" };

function UnenrollEvents() {
  const { student, eventsStudent } = useStudent();
  const [selectedEvent, setSelectedEvent] = useState();
  const [modal, setModal] = useState(false);

  function toggle(event) {
    setModal(!modal);
    setSelectedEvent(event);
  }

  return (
    <>
      {!student ? (
        <span>Carregando...</span>
      ) : (
        <>
          <MDBRow>
            <MDBCol style={sColForm} sm="12">
              Eventos que você está inscrito.
            </MDBCol>
          </MDBRow>
          <MDBListGroup style={{ width: "100%" }}>
            {eventsStudent.map((eS, index) => (
              <MDBListGroupItemS
                className="d-flex justify-content-between align-items-center"
                key={eS._id}
              >
                {eS.title}
                <MDBIconS icon="ban" onClick={() => toggle(eS)} />
              </MDBListGroupItemS>
            ))}
          </MDBListGroup>
          <ModalUnenrollEvent
            event={selectedEvent}
            toggle={toggle}
            stateModalUnenroll={modal}
          />
        </>
      )}
    </>
  );
}

export default UnenrollEvents;
