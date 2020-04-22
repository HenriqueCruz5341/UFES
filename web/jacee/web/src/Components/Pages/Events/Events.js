import React from "react";
import eventosImg from "../../../assets/img/eventos.jpg";
import { MDBMask, MDBView, MDBCol, MDBContainer } from "mdbreact";
import "../../../services/api";
import api from "../../../services/api";
import "./events.css";
import EventList from "./EventList/EventList";

class Events extends React.Component {
  constructor() {
    super();
    this.state = {
      search: "",
      events: []
    };
  }

  async loadEvents() {
    let tempEventos = await api.get("/api/event/");
    this.setState({ events: tempEventos.data.events });
  }

  componentDidMount() {
    this.loadEvents();
  }

  updateSearch(event) {
    this.setState({ search: event.target.value.substr(0, 20) });
  }

  render() {
    let filteredEvents = this.state.events.filter(event => {
      return (
        event.title.toLocaleLowerCase().indexOf(this.state.search) !== -1 ||
        event.description.toLocaleLowerCase().indexOf(this.state.search) !== -1
      );
    });

    return (
      <div className="events">
        <MDBView className="titlePage">
          <img src={eventosImg} className="img-fluid imgTitle" alt="eventos" />
          <MDBMask overlay="black-strong" className="flex-center">
            <h1 className="white-text" style={{ paddingTop: "100px" }}>
              Eventos
            </h1>
          </MDBMask>
        </MDBView>

        <MDBContainer>
          <MDBCol md="12">
            <form className="form-inline mt-4 mb-4">
              <input
                className="form-control form-control-md ml-2 w-100"
                type="text"
                placeholder="Procure por nomes e assuntos dos eventos..."
                aria-label="Search"
                value={this.state.search}
                onChange={this.updateSearch.bind(this)}
              />
            </form>
          </MDBCol>

          <EventList events={filteredEvents} />
        </MDBContainer>
      </div>
    );
  }
}

export default Events;
