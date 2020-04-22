import React from "react";
import { MDBBtn, MDBModal, MDBModalFooter } from "mdbreact";
import { MDBModalHeaderS, MDBModalBodyS } from "./style";
import { useToasts } from "react-toast-notifications";
import api from "../../../../services/api";
import { useStudent } from "../../../../Contexts/Student";

function ModalUnenrollEvent(props) {
  let { toggle, stateModalUnenroll, event } = props;
  const { student, setEventsStudent, eventsStudent } = useStudent();
  const { addToast } = useToasts();

  async function deletEvent() {
    let token = localStorage.getItem("LOGINJACEE_TOKEN");
    const idStudent = student._id;
    try {
      await api.patch(
        `/api/event/unenrollStudent/${event._id}`,
        { idStudent, idPerson: student.person._id },
        {
          headers: { "auth-token": token },
        }
      );
      addToast(`Desinscrito de ${event.title}.`, { appearance: "success" });
      updateEventsStudent(event);
      toggle(event);
    } catch (err) {
      addToast(err.response.data, { appearance: "error" });
      console.log(err.response);
    }
  }

  function updateEventsStudent(event) {
    console.log(event);
    let aux = eventsStudent.filter((elem) => elem._id !== event._id);
    console.log(aux);
    setEventsStudent([...aux]);
  }

  return !event ? (
    <></>
  ) : (
    <MDBModal
      isOpen={stateModalUnenroll}
      toggle={() => toggle(event)}
      fade={stateModalUnenroll}
      centered
    >
      <MDBModalHeaderS toggle={() => toggle(event)} style={{ color: "black" }}>
        Desinscrevendo
      </MDBModalHeaderS>
      <MDBModalBodyS style={{ color: "black" }}>
        Tem certeza que deseja desinscrever-se de <span>{event.title}</span>?
      </MDBModalBodyS>
      <MDBModalFooter>
        <MDBBtn size="sm" color="primary" onClick={() => toggle(event)}>
          Cancelar
        </MDBBtn>
        <MDBBtn size="sm" color="danger" onClick={deletEvent}>
          Sim
        </MDBBtn>
      </MDBModalFooter>
    </MDBModal>
  );
}

export default ModalUnenrollEvent;
