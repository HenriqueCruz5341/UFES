import React from "react";
import { MDBContainer } from "mdbreact";
import CollapseEvent from "../CollapseEvent/CollapseEvent";


function EventList(props){
    let {eventos} = props;
    return (
        <MDBContainer>
            <ul>
          {eventos.map(evento => (
          <li>{evento.nome}<CollapseEvent evento={evento}/></li>
          ))}
            </ul>
        </MDBContainer>
    );
}

export default EventList;