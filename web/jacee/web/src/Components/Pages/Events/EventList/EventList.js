import React from "react";
import { MDBContainer } from "mdbreact";
import CollapseEvent from "../CollapseEvent/CollapseEvent";
import "./eventList.css";

function EventList(props) {
  let { events } = props;
  return (
    <MDBContainer>
      <ul className="eventList">
        {events.map(event => (
          <li key={event._id}>
            <CollapseEvent event={event} />
          </li>
        ))}
      </ul>
    </MDBContainer>
  );
}

export default EventList;
