import React, { useState, useEffect, useRef, useCallback } from "react";
import "./setPersonalSchedule.css";
import { MDBRow, MDBCol, MDBListGroup, MDBBtn } from "mdbreact";
import api from "../../../../services/api";
import { MDBListGroupItemS, MDBBadgeS } from "./style";
import Tab from "../Tab/Tab";
import { useStudent } from "../../../../Contexts/Student";
import { useToasts } from "react-toast-notifications";

const scrollContainerStyle = { width: "100%", maxHeight: "350px" };
const sColForm = { color: "black", alignItems: "flex-start" };

function usePrevious(value) {
  const ref = useRef();
  useEffect(() => {
    ref.current = value;
  });
  return ref.current;
}

function SetPersonalSchedule() {
  const [events, setEvents] = useState([]);
  const [disabledEvents, setDisabledEvents] = useState([]);
  const [selectedEvents, setSelectedEvents] = useState([]);
  const [loading, setLoading] = useState(true);
  const [checkedEvents, setCheckedEvents] = useState([]);
  const { student, eventsStudent, setEventsStudent } = useStudent();
  const [conflitingEvents, setConflitingEvents] = useState([]);
  const prevSelectedEvents = usePrevious([...selectedEvents]);
  const [schedule, setSchedule] = useState([]); //dia da semana, horarios do dia, lista de eventos naquele horario
  const { addToast } = useToasts();

  useEffect(() => {
    async function getEvents() {
      let responseEvents;
      try {
        responseEvents = await api.get("/api/event/");
        setEvents([...responseEvents.data.events]);
        setLoading(false);
      } catch (err) {
        console.log(err.response);
      }
    }
    getEvents();
  }, [eventsStudent]);

  useEffect(() => {
    if (events.length > 0) {
      if (checkedEvents.length === 0) {
        initializeCheckedEvents();
        initializeSchedule();
      }
    } // eslint-disable-next-line
  }, [events]);

  const storeEventsStudent = useCallback(
    (newEventsStudent) => {
      setEventsStudent(newEventsStudent);
    },
    [setEventsStudent]
  );

  useEffect(() => {
    async function getEventsStudent() {
      let response;
      const idStudent = student._id;
      const token = localStorage.getItem("LOGINJACEE_TOKEN");

      try {
        response = await api.get(`/api/event/studentEvents/${idStudent}`, {
          headers: { "auth-token": token },
        });
        storeEventsStudent([...response.data.events]);
      } catch (err) {
        console.log(err.response);
      }
    }

    if (student) getEventsStudent();
  }, [student, storeEventsStudent]);

  useEffect(() => {
    function loadEventsStudent() {
      let idsEvents = events.map((elem) => elem._id);
      let teste = {
        selectedEvents: [],
        checkedEvents: events.map(() => false),
      };
      eventsStudent.forEach((event) => {
        let indexEvent = idsEvents.indexOf(event._id);
        teste.checkedEvents[indexEvent] = !teste.checkedEvents[indexEvent];
        teste.selectedEvents = [...teste.selectedEvents, event];
      });
      setCheckedEvents([...teste.checkedEvents]);
      setSelectedEvents([...teste.selectedEvents]);
    }

    if (events.length > 0) {
      loadEventsStudent();
    } // eslint-disable-next-line
  }, [eventsStudent, events]);

  useEffect(() => {
    if (prevSelectedEvents) {
      if (prevSelectedEvents.length > selectedEvents.length) {
        let removedEvent;
        for (let i = 0; i < prevSelectedEvents.length; i++) {
          if (
            selectedEvents
              .map((elem) => elem._id)
              .indexOf(prevSelectedEvents[i]._id) === -1
          ) {
            removedEvent = { ...prevSelectedEvents[i] };
          }
        }
        removeConflitingEvent(removedEvent);
      }
      if (prevSelectedEvents.length < selectedEvents.length) {
        let addEvents = [];
        let aux,
          aux1 = { disab: [], confli: [] };
        selectedEvents.forEach((selEve) => {
          if (
            prevSelectedEvents.map((elem) => elem._id).indexOf(selEve._id) ===
            -1
          )
            addEvents.push({ ...selEve });
        });
        addEvents.forEach((elem) => {
          aux = searchConflitingEvents(elem);
          aux1 = {
            disab: [...aux1.disab, ...aux.disab],
            confli: [...aux1.confli, ...aux.confli],
          };
        });
        setDisabledEvents([...aux1.disab]);
        setConflitingEvents([...aux1.confli]);
      }
    } // eslint-disable-next-line
  }, [selectedEvents]);

  function initializeSchedule() {
    let sched = [];
    for (let i = 0; i < 5; i++) {
      sched.push([]);
      for (let j = 0; j < 14; j++) {
        sched[i].push([]);
      }
    }

    let eveLis = [...events];
    for (let i = 0; i < eveLis.length; i++) {
      for (let j = 0; j < eveLis[i].eventPart.length; j++) {
        let day = new Date(eveLis[i].eventPart[j].date).getDay() - 1;
        let hour = new Date(eveLis[i].eventPart[j].date).getHours() - 4;
        let bufferHours = eveLis[i].eventPart[j].duration;
        let count = 0;
        while (bufferHours > 0) {
          sched[day][hour + count].push({
            _id: eveLis[i]._id,
            local: eveLis[i].eventPart[j].local,
            title: eveLis[i].title,
          });
          count++;
          bufferHours--;
        }
      }
    }
    setSchedule([...sched]);
  }

  function initializeCheckedEvents() {
    let checEven = [];
    for (let i = 0; i < events.length; i++) {
      checEven.push(false);
    }
    setCheckedEvents([...checEven]);
    setLoading(false);
  }

  function disabledEvent(event) {
    if (disabledEvents.indexOf(event._id) === -1) return false;
    return true;
  }

  function isCrowded(event) {
    if (
      event.vacancies === 0 &&
      event.enrolledStudents.indexOf(student._id) === -1
    )
      return true;
    return false;
  }

  function isEnrolled(index) {
    let idsEnrolled = eventsStudent.map((eS) => eS._id);
    let idEvent = events[index]._id;

    if (idsEnrolled.indexOf(idEvent) === -1) selectEvent(index, false);
  }

  function selectEvent(index) {
    let checEven = [...checkedEvents];
    checEven[index] = !checEven[index];
    let event = events[index];
    if (checEven[index]) {
      setSelectedEvents(selectedEvents.concat(event));
    } else {
      setSelectedEvents(
        selectedEvents.filter((elem) => elem._id !== event._id)
      );
    }
    setCheckedEvents([...checEven]);
  }

  function removeConflitingEvent(removedEvent) {
    let find = true;

    //Se a lista de eventos conflitanto estiver vazia, nao ah nada para fazer
    if (conflitingEvents.length === 0) return null;

    //Se o evento que foi removido da lista de selecionados não era conflitante, nao ah nada para fazer
    conflitingEvents.forEach((elem) => {
      if (elem.selected === removedEvent._id) {
        return (find = false);
      }
    });
    if (find) return null;

    //Pega os ids de eventos que estao em conflito exclusivamente com apenas um outro
    let listIdConflits = [...conflitingEvents.map((elem) => elem.confliting)];
    let idEvents = [];
    idEvents = listIdConflits
      .map((id) => {
        let count = 0;
        listIdConflits.forEach((id2) => {
          if (id2 === id) count++;
        });
        if (count === 1) return id;
        return null;
      })
      .filter((elem) => elem !== null);

    //Pega os ids de eventos que serão removidos da lista de eventos desabilitados
    let eventsOutDisabled = [];
    for (let i = 0; i < idEvents.length; i++) {
      for (let j = 0; j < conflitingEvents.length; j++) {
        if (conflitingEvents[j].selected === removedEvent._id) {
          if (conflitingEvents[j].confliting === idEvents[i]) {
            eventsOutDisabled = [...eventsOutDisabled, idEvents[i]];
          }
        }
      }
    }

    //Monta a nova lista de eventos desabilitados
    let disaEven = [...disabledEvents];
    for (let i = 0; i < eventsOutDisabled.length; i++) {
      disaEven = disaEven.filter((elem) => elem !== eventsOutDisabled[i]);
    }

    //Monta a nova lista de eventos em conflito
    let confEven = [];
    confEven = conflitingEvents.filter(
      (elem) => elem.selected !== removedEvent._id
    );

    //Remove as duplicaçoes de elementos
    let newDisaEven = [];
    disaEven.forEach((elem1) => {
      if (newDisaEven.filter((elem) => elem === elem1).length === 0) {
        newDisaEven.push(elem1);
      }
    });
    disaEven = [...newDisaEven];

    setConflitingEvents([...confEven]);
    setDisabledEvents([...disaEven]);
  }

  function searchConflitingEvents(event) {
    let confliting = [];

    for (let i = 0; i < event.eventPart.length; i++) {
      let day = new Date(event.eventPart[i].date).getDay() - 1;
      let hour = new Date(event.eventPart[i].date).getHours() - 4;
      let bufferHours = event.eventPart[i].duration;
      let count = 0;
      while (bufferHours > 0) {
        if (schedule[day][hour + count].length > 1) {
          confliting = [
            ...confliting,
            ...schedule[day][hour + count].filter(
              (elem) => elem._id !== event._id
            ),
          ];
        }
        bufferHours--;
        count++;
      }
    }

    let newConfliting = [];
    confliting.forEach((elem1) => {
      if (newConfliting.filter((elem) => elem._id === elem1._id).length === 0) {
        newConfliting.push({ ...elem1 });
      }
    });
    confliting = [...newConfliting];
    return {
      disab: [
        ...disabledEvents,
        ...confliting
          .filter((elem) => disabledEvents.indexOf(elem._id) === -1)
          .map((elem) => elem._id),
      ],
      confli: [
        ...conflitingEvents,
        ...confliting.map((elem) => ({
          selected: event._id,
          confliting: elem._id,
        })),
      ],
    };
  }

  async function handleSubmit(e) {
    e.preventDefault();
    const token = localStorage.getItem("LOGINJACEE_TOKEN");
    let idsEnrolled = eventsStudent.map((eS) => eS._id);
    let newEventsStudent = [];

    for (let i = 0; i < selectedEvents.length; i++) {
      if (idsEnrolled.indexOf(selectedEvents[i]._id) === -1) {
        try {
          await api.patch(
            `/api/event/enrollStudent/${selectedEvents[i]._id}`,
            { idStudent: student._id, idPerson: student.person._id },
            {
              headers: { "auth-token": token },
            }
          );
          newEventsStudent.push(selectedEvents[i]);
          addToast(`Inscrito em ${selectedEvents[i].title}.`, {
            appearance: "success",
          });
        } catch (err) {
          addToast(
            `Erro ao se inscrever em ${selectedEvents[i].title}. ${err.response.data}`,
            { appearance: "error" }
          );
          // console.log(err.response);
        }
      }
    }
    setEventsStudent([...eventsStudent, ...newEventsStudent]);
  }
  // console.warn("SELECTED", selectedEvents);
  // console.log("DISABLED", disabledEvents);
  // console.log("CONFLITING", conflitingEvents);
  // console.log("CHECKED", checkedEvents);
  // console.log("EVENTS", events);
  // console.log("EVENTSSTUDENT", eventsStudent);
  // console.log("STUDENT", student);
  return (
    <>
      {loading ? (
        <span style={{ color: "black" }}>Carregando...</span>
      ) : (
        <>
          <MDBRow>
            <MDBCol style={sColForm} sm="12">
              Escolha os eventos que deseja participar
            </MDBCol>
          </MDBRow>
          <MDBListGroup>
            <div
              className="scrollbar scrollbar-primary"
              style={scrollContainerStyle}
            >
              {events.map((event, index) => (
                <MDBListGroupItemS
                  className="d-flex justify-content-between align-items-center"
                  onClick={() => isEnrolled(index)}
                  data_active={checkedEvents[index].toString()}
                  key={index}
                  disabled={disabledEvent(event) || isCrowded(event)}
                >
                  {event.title}
                  <MDBBadgeS
                    color="succes"
                    data_disabled={event.vacancies}
                    pill
                  >
                    {event.vacancies}
                  </MDBBadgeS>
                </MDBListGroupItemS>
              ))}
            </div>
          </MDBListGroup>
          <MDBRow>
            <MDBCol sm="12">
              <MDBBtn
                color="primary"
                onClick={(e) => handleSubmit(e)}
                disabled={!selectedEvents.length}
              >
                Confirmar
              </MDBBtn>
            </MDBCol>
          </MDBRow>
          <MDBRow>
            <MDBCol sm="12" style={sColForm}>
              Seu horário ficará desse jeito
            </MDBCol>
          </MDBRow>
          <Tab events={selectedEvents} />
        </>
      )}
    </>
  );
}

export default SetPersonalSchedule;
