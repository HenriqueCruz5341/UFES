import React, { useState, useEffect, useCallback, useMemo } from "react";
import { MDBContainer, MDBCol, MDBRow, MDBBtn } from "mdbreact";
import api from "../../../../services/api";
import { Link } from "react-router-dom";

function MarkPresence() {
  const [query, setQuery] = useState("");
  const [loading, setLoading] = useState(true);
  const [events, setEvents] = useState();

  const getEvents = useCallback(async () => {
    let response;
    try {
      response = await api.get("/api/event/");
      setEvents(response.data.events);
      setLoading(false);
    } catch (err) {
      console.log(err.response);
    }
  }, []);

  useEffect(() => {
    getEvents();
  }, [getEvents]);

  const filteredEvents = useMemo(() => {
    return events?.filter(
      (event) => event.title.toLocaleLowerCase().indexOf(query) !== -1
    );
  }, [events, query]);

  return (
    <MDBContainer style={{ paddingTop: "150px" }}>
      {loading ? (
        <span>Carregando...</span>
      ) : (
        <>
          <MDBRow>
            <MDBCol sm="12">
              <form className="form-inline mt-4 mb-4">
                <input
                  className="form-control form-control-md ml-2 w-100"
                  type="text"
                  placeholder="Procure por nomes dos eventos..."
                  aria-label="Search"
                  value={query}
                  onChange={(e) => setQuery(e.target.value)}
                />
              </form>
            </MDBCol>
          </MDBRow>
          <div style={{ display: "inline-block" }}>
            {filteredEvents.map((event) => (
              <Link key={event._id} to={`/markPresence/${event._id}`}>
                <MDBBtn>{event.title}</MDBBtn>
              </Link>
            ))}
          </div>
        </>
      )}
    </MDBContainer>
  );
}

export default MarkPresence;
