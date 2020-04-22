import React, { useState, useEffect } from "react";
import { MDBContainer, MDBRow, MDBCol, MDBBtn, MDBIcon } from "mdbreact";
import api from "../../../../../services/api";
import { Link } from "react-router-dom";

function UpdateEvent(props) {
  const [event, setEvent] = useState();
  const [title, setTitle] = useState();
  const [responsable, setResponsable] = useState();
  const [previousKnowledge, setPreviousKnowledge] = useState();
  const [vacancies, setVacancies] = useState();
  const [description, setDescription] = useState();
  const [type, setType] = useState();
  const [material, setMaterial] = useState();
  const [inputParts, setInputParts] = useState([]);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    async function getEvent() {
      let response;
      let idEvent = props.history.location.pathname.split("/")[3];
      const token = localStorage.getItem("LOGINJACEE_TOKEN");
      try {
        response = await api.get(`/api/event/${idEvent}`, {
          headers: { "auth-token": token },
        });
        setEvent({ ...response.data.event[0] });
        console.log(response.data.event[0]);
        setLoading(false);
      } catch (err) {
        console.log(err.response);
      }
    }
    getEvent();
  }, [props]);

  useEffect(() => {
    if (event) {
      setTitle(event.title);
      setResponsable(event.responsable);
      setPreviousKnowledge(event.previousKnowledge[0]);
      setMaterial(event.material);
      setType(event.type);
      setDescription(event.description);
      setVacancies(event.vacancies);
      let listParts = [];
      event.eventPart.forEach((elem) => {
        console.log(elem);
        let partDate = elem.date.slice(0, 10);
        let partTime = elem.date.slice(11, 16);
        let part = {
          date: partDate,
          validDateForm: "",
          validDate: true,
          time: partTime,
          validTimeForm: "",
          validTime: true,
          duration: elem.duration,
          validDuration: true,
          local: elem.local,
        };
        console.log(part);
        listParts = [...listParts, part];
      });
      setInputParts([...listParts]);
    }
  }, [event]);

  function handleChange(e, index) {
    let aux = [...inputParts];
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
    setInputParts([...aux]);
  }

  function handleRemove(index) {
    let aux = [...inputParts];
    aux.splice(index, 1);
    setInputParts([...aux]);
  }

  function addClass() {
    setInputParts([
      ...inputParts,
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
    ]);
  }

  async function handleSubmit(e) {
    e.preventDefault();

    const token = localStorage.getItem("LOGINJACEE_TOKEN");
    let success = true;

    console.log(
      title,
      previousKnowledge,
      vacancies,
      description,
      material,
      responsable,
      type
    );

    try {
      await api.put(
        `/api/event/${event._id}`,
        {
          title,
          previousKnowledge,
          vacancies,
          description,
          material,
          responsable,
          type,
        },
        { headers: { "auth-token": token } }
      );
    } catch (err) {
      success = false;
      console.log(err.response);
    }

    event.eventPart.forEach(async (part) => {
      try {
        await api.delete(`/api/event/deleteEventPart/${part._id}`, {
          headers: { "auth-token": token },
        });
      } catch (err) {
        success = false;
        console.log(err.response);
      }
    });

    inputParts.forEach(async (part) => {
      let time = Number.parseInt(part.time.split(":")[0]) - 3;
      if (time < 10) time = "0" + time.toString();
      time += ":" + part.time.split(":")[1];
      let date = new Date(part.date + "T" + time + ":00");
      let duration = part.duration;
      let local = part.local;
      try {
        await api.post(
          `/api/event/addEventPart/${event._id}`,
          { date, duration, local },
          { headers: { "auth-token": token } }
        );
      } catch (err) {
        success = false;
        console.log(err.response);
      }
    });

    if (success) props.history.push("/eventsAdmin");
  }

  function isValidEvent() {
    let valid = true;
    inputParts.forEach((input) => {
      if (!input.validDate || !input.validTime || !input.validDuration)
        valid = false;
    });
    return valid;
  }

  return (
    <MDBContainer style={{ paddingTop: "150px" }}>
      <Link to="/eventsAdmin">
        <MDBBtn color="primary">Voltar</MDBBtn>
      </Link>
      {loading ? (
        <span>Carregando...</span>
      ) : (
        <form onSubmit={(e) => handleSubmit(e)}>
          <MDBRow>
            <MDBCol sm="12">
              <h3 style={{ color: "black" }}>Editação de Eventos</h3>
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
                value={title}
                onChange={(e) => setTitle(e.target.value)}
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
                value={responsable}
                onChange={(e) => setResponsable(e.target.value)}
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
                    value={previousKnowledge}
                    onChange={(e) => setPreviousKnowledge(e.target.value)}
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
                    value={material}
                    onChange={(e) => setMaterial(e.target.value)}
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
                value={description}
                onChange={(e) => setDescription(e.target.value)}
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
                onChange={(e) => setType(e.target.value)}
                value={type}
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
                value={vacancies}
                onChange={(e) => setVacancies(e.target.value)}
                required
              />
            </MDBCol>
          </MDBRow>
          {inputParts.map((input, index) => {
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
                      onChange={(e) => handleChange(e, index)}
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
                      onChange={(e) => handleChange(e, index)}
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
                      disabled={input.time === ""}
                      onChange={(e) => handleChange(e, index)}
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
                      onChange={(e) => handleChange(e, index)}
                      value={input.local}
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
                      onClick={() => handleRemove(index)}
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
          <MDBBtn color="primary" onClick={(e) => addClass(e)}>
            Adicionar aula
          </MDBBtn>

          <div className="text-center mt-4">
            <MDBBtn color="primary" type="submit" disabled={!isValidEvent()}>
              Confirmar
            </MDBBtn>
          </div>
        </form>
      )}
    </MDBContainer>
  );
}

export default UpdateEvent;
