import React, { Component } from "react";
import {
  MDBContainer,
  MDBTable,
  MDBTableBody,
  MDBTableHead,
  MDBBtn
} from "mdbreact";
import { Link } from "react-router-dom";
import Collapse from "../Collapse/Collapse";
import api from "../../../../../services/api";

class InspecEvents extends Component {
  state = {
    event: {},
    loading: true
  };

  componentDidMount() {
    this.getEvent();
  }

  componentDidUpdate(prevProps, prevState) {
    if (prevState.event !== this.state.event) {
      this.setState({ loading: false });
    }
  }

  async getEvent() {
    let response;
    let idEvent = this.props.history.location.pathname.split("/")[3];
    const token = localStorage.getItem("LOGINJACEE_TOKEN");
    try {
      response = await api.get(`/api/event/${idEvent}`, {
        headers: { "auth-token": token }
      });
      this.setState({ event: { ...response.data.event[0] } });
    } catch (err) {
      console.log(err.response);
    }
  }

  render() {
    return (
      <MDBContainer
        style={{ paddingTop: "150px" }}
        className="tableInspecEvent"
      >
        {this.state.loading ? (
          <div className="spinner-border" role="status"></div>
        ) : (
          <>
            <Link to="/eventsAdmin">
              <MDBBtn color="primary">Voltar</MDBBtn>
            </Link>
            <MDBTable responsive>
              <MDBTableHead>
                <tr>
                  <th colSpan="2">{this.state.event.title}</th>
                </tr>
              </MDBTableHead>
              <MDBTableBody>
                <tr>
                  <td>ID:</td>
                  <td>{this.state.event._id}</td>
                </tr>
                <tr>
                  <td>Descrição:</td>
                  <td>{this.state.event.description}</td>
                </tr>
                <tr>
                  <td>Responsavel:</td>
                  <td>{this.state.event.responsable}</td>
                </tr>
                <tr>
                  <td>Estudantes cadastrados:</td>
                  <td>
                    {this.state.event.enrolledStudents.length}{" "}
                    <Collapse
                      enrolledStudents={this.state.event.enrolledStudents}
                    />
                  </td>
                </tr>
                <tr>
                  <td>Aulas:</td>
                  <td>
                    {this.state.event.eventPart.length}{" "}
                    <Collapse eventPart={this.state.event.eventPart} />
                  </td>
                </tr>
                <tr>
                  <td>Material:</td>
                  <td>
                    <a href={this.state.event.material}>
                      {this.state.event.material}
                    </a>
                  </td>
                </tr>
                <tr>
                  <td>Conhecimento prévio:</td>
                  <td>{this.state.event.previousKnowledge[0]}</td>
                </tr>
                <tr>
                  <td>Tipo:</td>
                  <td>{this.state.event.type}</td>
                </tr>
                <tr>
                  <td>Total de vagas:</td>
                  <td>{this.state.event.vacancies}</td>
                </tr>
                <tr>
                  <td>Vagas sobrando:</td>
                  <td>
                    {this.state.event.vacancies -
                      this.state.event.enrolledStudents.length}
                  </td>
                </tr>
              </MDBTableBody>
            </MDBTable>
          </>
        )}
      </MDBContainer>
    );
  }
}

export default InspecEvents;
