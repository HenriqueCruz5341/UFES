import React, { useEffect, useState } from "react";
import { MDBContainer, MDBRow, MDBBtn, MDBCol } from "mdbreact";
import { Link } from "react-router-dom";
import CollapseEventPart from "../CollapseEventPart/CollapseEventPart";
import api from "../../../../../services/api";

function MarkPresenceEvent(props) {
  const [event, setEvent] = useState();
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    async function getEvent() {
      let response;
      let idEvent = props.history.location.pathname.split("/")[2];
      const token = localStorage.getItem("LOGINJACEE_TOKEN");
      try {
        response = await api.get(`/api/event/${idEvent}`, {
          headers: { "auth-token": token },
        });
        setEvent(response.data.event[0]);
        setLoading(false);
      } catch (err) {
        console.log(err.response);
      }
    }
    getEvent();
  }, [props]);

  const orderEventParts = () => {
    return event?.eventPart.sort(function (a, b) {
      return new Date(a.date) - new Date(b.date);
    });
  };

  return (
    <MDBContainer style={{ paddingTop: "150px" }}>
      <MDBRow>
        <Link to="/markPresence">
          <MDBBtn color="primary">Voltar</MDBBtn>
        </Link>
      </MDBRow>
      {loading ? (
        <div className="spinner-border" role="status"></div>
      ) : (
        <>
          <MDBRow>
            <MDBCol sm="12">
              <h3 style={{ color: "black" }}>{event.title}</h3>
            </MDBCol>
          </MDBRow>
          {orderEventParts().map((part) => (
            <CollapseEventPart
              key={part._id}
              students={event.enrolledStudents}
              people={event.enrolledPeople}
              part={part}
            >
              {part.date}
            </CollapseEventPart>
          ))}
        </>
      )}
    </MDBContainer>
  );
}

export default MarkPresenceEvent;
