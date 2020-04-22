import React, { Component } from "react";
import { MDBBtn, MDBCollapse, MDBIcon, MDBContainer } from "mdbreact";
import "./collapseEvent.css";

class CollapseEvent extends Component {
  state = {
    collapseID: ""
  };

  constructor(props) {
    super();
    this.state = {
      icone: <MDBIcon icon="angle-down" />
    };
  }

  toggleCollapse = collapseID => () => {
    this.setState(prevState => ({
      collapseID: prevState.collapseID !== collapseID ? collapseID : ""
    }));
  };

  dateConvert(dateI) {
    let dateC = dateI.slice(8, 10) + "/" + dateI.slice(5, 7);

    return dateC;
  }

  timeConvert(timeI) {
    let timeC = timeI.slice(11, 16);

    return timeC;
  }

  render() {
    let { event } = this.props;
    return (
      <>
        <MDBBtn
          color="mdb-color"
          onClick={this.toggleCollapse("basicCollapse")}
          className="botaoCollapse"
        >
          <div className="conteudoBotao">
            <strong>{event.title}</strong>
            <div className="iconesBotao">{this.state.icone}</div>
          </div>
        </MDBBtn>
        <MDBCollapse
          className="conteudoCollapse"
          onOpened={() => this.setState({ icone: <MDBIcon icon="angle-up" /> })}
          onClosed={() =>
            this.setState({ icone: <MDBIcon icon="angle-down" /> })
          }
          id="basicCollapse"
          isOpen={this.state.collapseID}
        >
          <MDBContainer>
            <p>
              <strong>Tipo: </strong>
              {event.type}
            </p>
            <p>
              <strong>Responsável: </strong>
              {event.responsable}
            </p>
            <p>
              <strong>Descrição: </strong>
              {event.description}
            </p>
            <strong>Horários:</strong>
            <ul>
              {event.eventPart.map(eventPart => (
                <li key={eventPart.local}>
                  <strong>{this.dateConvert(eventPart.date)} </strong>
                  às {this.timeConvert(eventPart.date)} no {eventPart.local}
                </li>
              ))}
            </ul>
            <br />
          </MDBContainer>
        </MDBCollapse>
      </>
    );
  }
}

export default CollapseEvent;
