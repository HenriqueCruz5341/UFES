import React, { Component } from "react";
import { MDBContainer, MDBDataTable, MDBBtn, MDBIcon } from "mdbreact";
import api from "../../../../services/api";
import "./eventsAdmin.css";
import { Link } from "react-router-dom";
import ModalDelete from "../ModalDelete/ModalDelete";

class EventsAdmin extends Component {
  state = {
    data: {
      columns: [
        {
          label: "Título",
          field: "title",
          sort: "asc"
        },
        {
          label: "Total de vagas",
          field: "vacancies",
          sort: "asc"
        },
        {
          label: "Responsável",
          field: "responsable",
          sort: "asc"
        },
        {
          label: "Qtd de partes",
          field: "nParts",
          sort: "asc"
        },
        {
          label: "Tipo",
          field: "type",
          sort: "asc"
        },
        {
          label: "Ações",
          field: "action"
        }
      ],
      rows: []
    },
    modal: false,
    selectedEvent: {}
  };

  toggle(event) {
    this.setState({
      modal: !this.state.modal,
      selectedEvent: event
    });
  }

  loadEvents = async () => {
    let tempEvents = await api.get("/api/event/");
    let rows = [];
    tempEvents.data.events.map(event => {
      return (rows = [
        ...rows,
        {
          _id: event._id,
          title: event.title,
          vacancies: event.vacancies,
          nParts: event.eventPart.length,
          responsable: event.responsable,
          type: event.type,
          action: (
            <div>
              <Link to={"/eventsAdmin/update/" + event._id}>
                <MDBBtn color="warning" size="sm">
                  <MDBIcon size="lg" icon="edit" />
                </MDBBtn>
              </Link>
              <Link to={"/eventsAdmin/inspect/" + event._id}>
                <MDBBtn color="primary" size="sm">
                  <MDBIcon size="lg" icon="eye" />
                </MDBBtn>
              </Link>
              <MDBBtn
                onClick={() => this.toggle(event)}
                color="danger"
                size="sm"
              >
                <MDBIcon size="lg" icon="trash" />
              </MDBBtn>
            </div>
          )
        }
      ]);
    });
    tempEvents = { columns: this.state.data.columns, rows: rows };
    this.setState({ data: tempEvents });
  };

  componentDidMount() {
    this.loadEvents();
  }

  render() {
    return (
      <MDBContainer style={{ paddingTop: "150px" }}>
        <Link to="/eventsAdmin/register">
          <MDBBtn color="primary">Cadastrar novo evento</MDBBtn>
        </Link>
        <MDBDataTable
          className="tableEventsAdmin"
          striped
          responsive
          displayEntries={false}
          bordered
          hover
          noBottomColumns
          data={this.state.data}
        />

        <ModalDelete
          load={this.loadEvents}
          item={this.state.selectedEvent}
          toggle={this.toggle.bind(this)}
          stateModalDelete={this.state.modal}
          type="event"
        />
      </MDBContainer>
    );
  }
}

export default EventsAdmin;
