import React from "react";
import TabSchedule from "./TabSchedule/TabSchedule";
import cronograma from "../../../assets/img/cronograma.jpg";
import { MDBMask, MDBView } from "mdbreact";
import "./schedule.css";

function Schedule() {
  return (
    <div className="schedule">
      <MDBView className="titlePage">
        <img src={cronograma} className="img-fluid imgTitle" alt="cronograma" />
        <MDBMask overlay="black-strong" className="flex-center">
          <h1 className="white-text" style={{ paddingTop: "100px" }}>
            Cronograma
          </h1>
        </MDBMask>
      </MDBView>
      <TabSchedule />
    </div>
  );
}

export default Schedule;
