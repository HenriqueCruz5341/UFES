import React, { useState, useEffect, useCallback } from "react";
import { MDBContainer, MDBCol } from "mdbreact";
import api from "../../../../services/api";
import InputMask from "react-input-mask";
import jsonWebTokenService from "jsonwebtoken";
import { useStudent } from "../../../../Contexts/Student";
import { useToasts } from "react-toast-notifications";
import ModalChangePassword from "./ModalChangePassword/ModalChangePassword";
import { MDBBtnS } from "../../../../globalStyle";
import { MDBRowS, InputEdit, MDBIconS, InputMaskS, MDBColS } from "./style";

function EditProfile() {
  const { setStudent } = useStudent();
  const [editedStudant, setEditedStudant] = useState();
  const [editName, setEditName] = useState(false);
  const [editEmail, setEditEmail] = useState(false);
  const [editPhone, setEditPhone] = useState(false);
  const [editInstitution, setEditInstitution] = useState(false);
  const [editCourse, setEditCourse] = useState(false);
  const [loading, setLoading] = useState(true);
  const [modal, setModal] = useState(false);
  const { addToast } = useToasts();

  const storeStudent = useCallback(
    (newStudent) => {
      setStudent(newStudent);
    },
    [setStudent]
  );

  useEffect(() => {
    async function getStudent() {
      const token = localStorage.getItem("LOGINJACEE_TOKEN");
      const personId = jsonWebTokenService.decode(token)._id;
      const response = await api.get(`/api/student/getStudent/${personId}`);
      storeStudent({ ...response.data.student });
      setEditedStudant({ ...response.data.student });
      setLoading(false);
    }
    getStudent();
  }, [storeStudent]);

  function handleChangePerson(e) {
    let aux = { ...editedStudant };
    aux["person"][e.target.name] = e.target.value;
    setEditedStudant(aux);
  }

  function handleChangeStudent(e) {
    let aux = { ...editedStudant };
    aux[e.target.name] = e.target.value;
    setEditedStudant(aux);
  }

  function toggle() {
    setModal(!modal);
  }

  async function handleSubmit(e) {
    e.preventDefault();
    const token = localStorage.getItem("LOGINJACEE_TOKEN");
    let data = {
      name: editedStudant.person.name,
      email: editedStudant.person.email,
      password: editedStudant.person.password,
      accessLevel: editedStudant.person.accessLevel,
      cpf: editedStudant.cpf,
      phone: editedStudant.person.phone,
      paid: editedStudant.paid,
      hours: editedStudant.hours,
      institution: editedStudant.institution,
      course: editedStudant.course,
    };
    try {
      await api.put(`/api/student/${editedStudant._id}`, data, {
        headers: { "auth-token": token },
      });
      addToast("Edição feita com sucesso!", { appearance: "success" });
    } catch (err) {
      addToast(err.response.data, { appearance: "error" });
    }
  }

  function renderForm() {
    if (loading) return <span style={{ color: "black" }}>Carregando...</span>;
    return (
      <>
        <MDBRowS>
          <MDBCol md="12">
            <h2>
              <b>Configurações da Conta</b>
            </h2>
            <br />
          </MDBCol>
        </MDBRowS>
        <form onSubmit={handleSubmit}>
          <MDBRowS start>
            <MDBCol sm="12">
              <label htmlFor="iname">Nome Completo</label>
              <InputEdit>
                <InputMaskS
                  className="form-control"
                  type="text"
                  name="name"
                  id="iname"
                  disabled={!editName}
                  value={editedStudant.person.name}
                  onChange={handleChangePerson}
                  required
                />
                <MDBIconS
                  icon="edit"
                  style={{ cursor: "pointer" }}
                  onClick={() => setEditName(!editName)}
                />
              </InputEdit>
            </MDBCol>
          </MDBRowS>
          <MDBRowS>
            <MDBCol sm="7">
              <strong>Status do Pagamento:</strong>{" "}
              {!editedStudant.paid ? "Aguardando Pagamento" : "Pago"}
            </MDBCol>
            <MDBCol sm="5">
              <strong>Horas Cumpridas:</strong> {editedStudant.hours}
            </MDBCol>
          </MDBRowS>
          <MDBRowS start>
            <MDBCol sm="8">
              <label htmlFor="iemail">Email</label>
              <InputEdit>
                <InputMaskS
                  className="form-control"
                  type="email"
                  name="email"
                  id="iemail"
                  disabled={!editEmail}
                  value={editedStudant.person.email}
                  onChange={handleChangePerson}
                  required
                />
                <MDBIconS
                  icon="edit"
                  style={{ cursor: "pointer" }}
                  onClick={() => setEditEmail(!editEmail)}
                />
              </InputEdit>
            </MDBCol>
            <MDBCol sm="4" style={{ display: "table", height: "70px" }}>
              <div
                style={{
                  display: "table-cell",
                  verticalAlign: "bottom",
                  textAlign: "center",
                }}
              >
                <MDBBtnS btncolor="rgb(247, 180, 5)" size="sm" onClick={toggle}>
                  Mudar senha
                </MDBBtnS>
              </div>
            </MDBCol>
          </MDBRowS>
          <MDBRowS start>
            <MDBColS sm="7">
              <label htmlFor="icpf">CPF</label>
              <InputMask
                mask="999.999.999-99"
                id="icpf"
                className="form-control"
                name="cpf"
                disabled
                value={editedStudant.cpf}
                required
                minLength="14"
              />
            </MDBColS>
            <MDBCol sm="5">
              <label htmlFor="iphone">Telefone</label>
              <InputEdit>
                <InputMaskS
                  mask="(99) 99999-9999"
                  id="iphone"
                  className="form-control"
                  name="phone"
                  disabled={!editPhone}
                  value={editedStudant.person.phone}
                  onChange={handleChangePerson}
                  required
                  minLength="15"
                />
                <MDBIconS
                  icon="edit"
                  style={{ cursor: "pointer" }}
                  onClick={() => setEditPhone(!editPhone)}
                />
              </InputEdit>
            </MDBCol>
          </MDBRowS>
          <MDBRowS start>
            <MDBColS sm="6">
              <label htmlFor="iinstitution">Instituição</label>
              <InputEdit>
                <InputMaskS
                  className="form-control"
                  type="text"
                  name="institution"
                  id="iinstitution"
                  disabled={!editInstitution}
                  value={editedStudant.institution}
                  onChange={handleChangeStudent}
                  required
                />
                <MDBIconS
                  icon="edit"
                  style={{ cursor: "pointer" }}
                  onClick={() => setEditInstitution(!editInstitution)}
                />
              </InputEdit>
            </MDBColS>
            <MDBCol sm="6">
              <label htmlFor="icourse">Curso</label>
              <InputEdit>
                <InputMaskS
                  className="form-control"
                  type="text"
                  name="course"
                  id="icourse"
                  disabled={!editCourse}
                  value={editedStudant.course}
                  onChange={handleChangeStudent}
                  required
                />
                <MDBIconS
                  icon="edit"
                  style={{ cursor: "pointer" }}
                  onClick={() => setEditCourse(!editCourse)}
                />
              </InputEdit>
            </MDBCol>
          </MDBRowS>
          <MDBRowS>
            <MDBCol sm="12" style={{ textAlign: "center" }}>
              <MDBBtnS btncolor="rgb(19, 156, 217)" type="submit">
                Salvar Mudanças
              </MDBBtnS>
            </MDBCol>
          </MDBRowS>
        </form>
        <ModalChangePassword toggle={() => toggle()} stateModal={modal} />
      </>
    );
  }

  return <MDBContainer fluid>{renderForm()}</MDBContainer>;
}

export default EditProfile;
