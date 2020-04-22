import React, { createContext, useState, useContext } from "react";

const StudentContext = createContext();

export default function StudentProvider({ children }) {
  const [student, setStudent] = useState();
  const [eventsStudent, setEventsStudent] = useState([]);

  return (
    <StudentContext.Provider
      value={{
        student,
        setStudent,
        eventsStudent,
        setEventsStudent
      }}
    >
      {children}
    </StudentContext.Provider>
  );
}

export function useStudent() {
  const context = useContext(StudentContext);
  const { student, setStudent, eventsStudent, setEventsStudent } = context;

  return { student, setStudent, eventsStudent, setEventsStudent };
}
