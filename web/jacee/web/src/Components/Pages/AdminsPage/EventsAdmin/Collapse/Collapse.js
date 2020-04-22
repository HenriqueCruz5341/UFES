import React, { Component } from "react";
import { MDBCollapse, MDBIcon } from "mdbreact";

class Collapse extends Component {
  state = {
    collapseID: "",
    isOpen: false,
    icon: "angle-down",
    eventPart: [],
    renderOption: true,
    students: [],
  };

  constructor(props) {
    super();
  }

  toggleCollapse = (collapseID) => () => {
    this.setState({ isOpen: !this.state.isOpen });
    if (this.state.isOpen) this.setState({ icon: "angle-down" });
    else this.setState({ icon: "angle-up" });
    this.setState((prevState) => ({
      collapseID: prevState.collapseID !== collapseID ? collapseID : "",
    }));
  };

  dateConvert(dateI) {
    let dateC = dateI.slice(8, 10) + "/" + dateI.slice(5, 7);

    return dateC;
  }

  timeConvert(timeI) {
    let timeC = timeI.slice(11, 16);

    return timeC;
  }

  componentDidMount() {
    console.log(this.props);
    if (this.props.eventPart) {
      this.setState({ eventPart: this.props.eventPart });
      console.log(this.state.eventPart);
    } else {
      this.setState({ students: [...this.props.enrolledStudents] });
      console.warn(this.props.enrolledStudents);
      this.setState({ renderOption: false });
    }
  }

  render() {
    return (
      <>
        <MDBIcon
          style={{ cursor: "pointer" }}
          icon={this.state.icon}
          onClick={this.toggleCollapse("basicCollapse")}
        />
        {this.state.renderOption ? (
          <MDBCollapse id="basicCollapse" isOpen={this.state.collapseID}>
            <ul>
              {this.state.eventPart.map((eventPart, index) => {
                return (
                  <li key={index}>
                    Data: {this.dateConvert(eventPart.date) + " | "}
                    Hora: {this.timeConvert(eventPart.date) + " | "}
                    Duração: {eventPart.duration + " | "}
                    Local: {eventPart.local}
                  </li>
                );
              })}
            </ul>
          </MDBCollapse>
        ) : (
          <MDBCollapse id="basicCollapse" isOpen={this.state.collapseID}>
            <ul>
              {this.state.students.map((student, index) => {
                return <li key={index}>{student.cpf}</li>;
              })}
            </ul>
          </MDBCollapse>
        )}
      </>
    );
  }
}

export default Collapse;
