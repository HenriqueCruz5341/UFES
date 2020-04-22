import React from "react";
import { MDBContainer } from "mdbreact";

//import { Accordion, AccordionItem, AccordionItemHeading, AccordionItemButton, AccordionItemPanel} from 'react-accessible-accordion';

// Demo styles, see 'Styles' section below for some notes on use.
import "./eventList01.css";

function EventList01(props) {
  let { eventos } = props;

  return (
    <MDBContainer>
      {eventos.map(evento => (
        <Accordion allowZeroExpanded={true} allowMultipleExpanded={true}>
          <AccordionItem>
            <AccordionItemHeading>
              <AccordionItemButton>{evento.nome}</AccordionItemButton>
            </AccordionItemHeading>
            <div className="accordion-css-transition">
              <AccordionItemPanel>
                <p>Tipo: {evento.tipo}</p>
                <p>Responsável: {evento.responsavel}</p>
                <p>
                  Data: {evento.inicio} - {evento.dia} - {evento.lugar}
                </p>
                <p>Descrição: {evento.descricao}</p>
              </AccordionItemPanel>
            </div>
          </AccordionItem>
        </Accordion>
      ))}
    </MDBContainer>
  );
}

export default EventList01;
