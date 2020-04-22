import React, { Component } from "react";
import { MDBContainer, MDBRow, MDBCol, MDBBtn, MDBIcon } from "mdbreact";
import api from "../../../../../services/api";
import { Link } from "react-router-dom";

class RegisterEvents extends Component {
  state = {
    title: "",
    responsable: "",
    previousKnowledge: "",
    vacancies: "",
    description: "",
    type: "",
    material: "",
    inputParts: [
      {
        date: "",
        validDateForm: "",
        validDate: false,
        time: "",
        validTimeForm: "",
        validTime: false,
        duration: "",
        validDurationForm: "",
        validDuration: false,
        local: "",
      },
    ],
  };

  changeHandler = (event) => {
    this.setState({ [event.target.name]: event.target.value });
  };

  handleChange(e, index) {
    let aux = [...this.state.inputParts];
    aux[index][e.target.name] = e.target.value;
    if (e.target.name === "date") {
      if (new Date(e.target.value).getDay() > 4) {
        aux[index]["validDateForm"] = "is-invalid";
        aux[index]["validDate"] = false;
      } else {
        aux[index]["validDateForm"] = "is-valid";
        aux[index]["validDate"] = true;
      }
    } else if (e.target.name === "time") {
      let time = Number.parseInt(e.target.value.split(":")[0]);
      if (time >= 7 && time <= 18) {
        aux[index]["validTimeForm"] = "is-valid";
        aux[index]["validTime"] = true;
      } else {
        aux[index]["validTimeForm"] = "is-invalid";
        aux[index]["validTime"] = false;
      }
    } else if (e.target.name === "duration") {
      let end =
        Number.parseInt(aux[index]["time"].split(":")[0]) +
        Number.parseInt(e.target.value);
      if (end > 19 || e.target.value === "" || e.target.value === "0") {
        aux[index]["validDurationForm"] = "is-invalid";
        aux[index]["validDuration"] = false;
      } else {
        aux[index]["validDurationForm"] = "is-valid";
        aux[index]["validDuration"] = true;
      }
    }
    this.setState({ inputParts: [...aux] });
  }

  handleRemove(index) {
    this.state.inputParts.splice(index, 1);
    this.setState({ inputParts: this.state.inputParts });
  }

  addAulas() {
    this.setState({
      inputParts: [
        ...this.state.inputParts,
        {
          date: "",
          validDateForm: "",
          validDate: false,
          time: "",
          validTimeForm: "",
          validTime: false,
          duration: "",
          validDurationForm: "",
          validDuration: false,
          local: "",
        },
      ],
    });
  }

  async handleSubmit(e) {
    let responseEventMaster;
    let title = this.state.title;
    let responsable = this.state.responsable;
    let previousKnowledge = this.state.previousKnowledge;
    let vacancies = this.state.vacancies;
    let description = this.state.description;
    let type = this.state.type;
    let material = this.state.material;
    let success = true;
    const token = localStorage.getItem("LOGINJACEE_TOKEN");
    e.preventDefault();
    try {
      responseEventMaster = await api.post(
        "/api/event/",
        {
          title,
          responsable,
          previousKnowledge,
          vacancies,
          description,
          type,
          material,
        },
        { headers: { "auth-token": token } }
      );
    } catch (err) {
      success = false;
      console.log(err.response);
    }

    if (responseEventMaster) {
      let idEventMaster = responseEventMaster.data._id;
      this.state.inputParts.map(async (eventPart) => {
        let time = Number.parseInt(eventPart.time.split(":")[0]) - 3;
        if (time < 10) time = "0" + time.toString();
        time += ":" + eventPart.time.split(":")[1];
        let date = new Date(eventPart.date + "T" + time + ":00");
        let duration = eventPart.duration;
        let local = eventPart.local;
        console.log(date);
        try {
          await api.post(
            `/api/event/addEventPart/${idEventMaster}`,
            { date, duration, local },
            { headers: { "auth-token": token } }
          );
        } catch (err) {
          success = false;
          console.log(err.response);
        }
      });
    }

    if (success) this.props.history.push("/eventsAdmin");
  }

  isValidEvent() {
    let valid = true;
    this.state.inputParts.forEach((input) => {
      if (!input.validDate || !input.validTime || !input.validDuration)
        valid = false;
    });
    return valid;
  }

  render() {
    return (
      <MDBContainer style={{ paddingTop: "150px" }}>
        <Link to="/eventsAdmin">
          <MDBBtn color="primary">Voltar</MDBBtn>
        </Link>
        <form onSubmit={(e) => this.handleSubmit(e)}>
          <MDBRow>
            <MDBCol sm="12">
              <h3 style={{ color: "black" }}>Cadastro de Eventos</h3>
            </MDBCol>
          </MDBRow>
          <MDBRow>
            <MDBCol sm="7">
              <label htmlFor="ititle" className="grey-text">
                Título
              </label>
              <input
                type="text"
                id="ititle"
                className="form-control"
                name="title"
                value={this.state.title}
                onChange={this.changeHandler}
                required
              />
            </MDBCol>
            <MDBCol sm="5">
              <label htmlFor="iresponsable" className="grey-text">
                Responsável
              </label>
              <input
                type="text"
                id="iresponsable"
                className="form-control"
                name="responsable"
                value={this.state.responsable}
                onChange={this.changeHandler}
                required
              />
            </MDBCol>
          </MDBRow>
          <MDBRow>
            <MDBCol sm="7">
              <MDBRow style={{ width: "100%" }}>
                <MDBCol sm="12" style={{ padding: "1rem 0px" }}>
                  <label htmlFor="ipreviewKnowledge" className="grey-text">
                    Conhecimento prévio
                  </label>
                  <input
                    type="text"
                    id="ipreviewKnowledge"
                    className="form-control"
                    name="previousKnowledge"
                    value={this.state.previousKnowledge}
                    onChange={this.changeHandler}
                    required
                  />
                </MDBCol>
              </MDBRow>
              <MDBRow style={{ width: "100%" }}>
                <MDBCol sm="12" style={{ padding: "1rem 0px" }}>
                  <label htmlFor="imaterial" className="grey-text">
                    Material
                  </label>
                  <input
                    type="text"
                    id="imaterial"
                    className="form-control"
                    name="material"
                    value={this.state.material}
                    onChange={this.changeHandler}
                    required
                  />
                </MDBCol>
              </MDBRow>
            </MDBCol>
            <MDBCol sm="5">
              <label htmlFor="idescription" className="grey-text">
                Descrição
              </label>
              <textarea
                id="idescription"
                className="form-control"
                name="description"
                value={this.state.description}
                onChange={this.changeHandler}
                rows="7"
                required
              />
            </MDBCol>
          </MDBRow>
          <MDBRow>
            <MDBCol sm="6">
              <label htmlFor="itype" className="grey-text">
                Tipo de evento
              </label>
              <select
                id="itype"
                name="type"
                className="browser-default custom-select"
                onChange={this.changeHandler}
                required
              >
                <option value="">Escolha uma opção</option>
                <option value="Minicurso prático">Minicurso prático</option>
                <option value="Aula teórica">Aula teórica</option>
                <option value="Palestra">Palestra</option>
              </select>
            </MDBCol>
            <MDBCol sm="6">
              <label htmlFor="ivacancies" className="grey-text">
                Quantidade de vagas
              </label>
              <input
                type="number"
                id="ivacancies"
                className="form-control"
                name="vacancies"
                value={this.state.vacancies}
                onChange={this.changeHandler}
                required
              />
            </MDBCol>
          </MDBRow>
          {this.state.inputParts.map((input, index) => {
            return (
              <fieldset key={index}>
                <legend
                  className="grey-text"
                  style={{ transform: "translatey(20px)" }}
                >
                  Aula {index + 1}
                </legend>
                <MDBRow>
                  <MDBCol md="3">
                    <label htmlFor={`idate${index}`} className="grey-text">
                      Data
                    </label>
                    <input
                      className={`form-control ${input.validDateForm}`}
                      type="date"
                      name="date"
                      id={`idate${index}`}
                      value={input.date}
                      onChange={(e) => this.handleChange(e, index)}
                      required
                    />
                  </MDBCol>
                  <MDBCol md="2">
                    <label htmlFor={`itime${index}`} className="grey-text">
                      Hora Início
                    </label>
                    <input
                      className={`form-control ${input.validTimeForm}`}
                      type="time"
                      name="time"
                      id={`itime${index}`}
                      value={input.time}
                      onChange={(e) => this.handleChange(e, index)}
                      required
                    />
                  </MDBCol>
                  <MDBCol md="2">
                    <label htmlFor={`iduration${index}`} className="grey-text">
                      Duração
                    </label>
                    <input
                      className={`form-control ${input.validDurationForm}`}
                      type="number"
                      name="duration"
                      id={`iduration${index}`}
                      value={input.duration}
                      onChange={(e) => this.handleChange(e, index)}
                      disabled={input.time === "" ? true : false}
                      required
                    />
                  </MDBCol>
                  <MDBCol md="3">
                    <label htmlFor={`ilocal${index}`} className="grey-text">
                      Local
                    </label>
                    <select
                      id={`ilocal${index}`}
                      name="local"
                      className="browser-default custom-select"
                      onChange={(e) => this.handleChange(e, index)}
                      required
                    >
                      <option value="">Escolha uma opção</option>
                      <option value="LabGrad1">LabGrad1</option>
                      <option value="LabGrad2">LabGrad2</option>
                      <option value="LCEE">LCEE</option>
                      <option value="LabZorro">LabZorro</option>
                      <option value="Auditorio">Auditório</option>
                    </select>
                  </MDBCol>
                  <MDBCol md="2">
                    <MDBBtn
                      size="sm"
                      onClick={() => this.handleRemove(index)}
                      color="danger"
                      className="botaoRemoverPartEvento"
                      style={{ transform: "translatey(15px)" }}
                    >
                      <MDBIcon icon="minus-circle" size="2x" />
                    </MDBBtn>
                  </MDBCol>
                </MDBRow>
              </fieldset>
            );
          })}
          <MDBBtn color="primary" onClick={(e) => this.addAulas(e)}>
            Adicionar aula
          </MDBBtn>

          <div className="text-center mt-4">
            <MDBBtn
              disabled={!this.isValidEvent()}
              color="unique"
              type="submit"
              onClick={(e) => this.handleSubmit(e)}
            >
              Register
            </MDBBtn>
          </div>
        </form>
      </MDBContainer>
    );
  }
}

export default RegisterEvents;
