import React from "react";
import { MDBContainer } from "mdbreact";
import CollapseEvent from "../CollapseEvent/CollapseEvent";
import './eventList.css';


function EventList(props){
    let {eventos} = props;
    return (
        <MDBContainer>
            <ul>
          {eventos.map(evento => (
          <li key={evento.id}><CollapseEvent evento={evento}/></li>
          ))}
            </ul>
        </MDBContainer>
    );
}

export default EventList;