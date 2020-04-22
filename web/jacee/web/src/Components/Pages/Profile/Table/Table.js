import React, { Component } from "react";
import { MDBTable, MDBTableBody, MDBTableHead } from "mdbreact";
import "./table.css";

class Table extends Component {
  state = {
    rows: [
      {
        hour: "7:00",
        labgrad1: "",
        labgrad2: "",
        lcee: "",
        labzorro: "",
        auditorio: "",
        teoricos: ""
      },
      {
        hour: "8:00",
        labgrad1: "",
        labgrad2: "",
        lcee: "",
        labzorro: "",
        auditorio: "",
        teoricos: ""
      },
      {
        hour: "9:00",
        labgrad1: "",
        labgrad2: "",
        lcee: "",
        labzorro: "",
        auditorio: "",
        teoricos: ""
      },
      {
        hour: "10:00",
        labgrad1: "",
        labgrad2: "",
        lcee: "",
        labzorro: "",
        auditorio: "",
        teoricos: ""
      },
      {
        hour: "11:00",
        labgrad1: "",
        labgrad2: "",
        lcee: "",
        labzorro: "",
        auditorio: "",
        teoricos: ""
      },
      {
        hour: "12:00",
        labgrad1: "",
        labgrad2: "",
        lcee: "",
        labzorro: "",
        auditorio: "",
        teoricos: ""
      },
      {
        hour: "13:00",
        labgrad1: "",
        labgrad2: "",
        lcee: "",
        labzorro: "",
        auditorio: "",
        teoricos: ""
      },
      {
        hour: "14:00",
        labgrad1: "",
        labgrad2: "",
        lcee: "",
        labzorro: "",
        auditorio: "",
        teoricos: ""
      },
      {
        hour: "15:00",
        labgrad1: "",
        labgrad2: "",
        lcee: "",
        labzorro: "",
        auditorio: "",
        teoricos: ""
      },
      {
        hour: "16:00",
        labgrad1: "",
        labgrad2: "",
        lcee: "",
        labzorro: "",
        auditorio: "",
        teoricos: ""
      },
      {
        hour: "17:00",
        labgrad1: "",
        labgrad2: "",
        lcee: "",
        labzorro: "",
        auditorio: "",
        teoricos: ""
      },
      {
        hour: "18:00",
        labgrad1: "",
        labgrad2: "",
        lcee: "",
        labzorro: "",
        auditorio: "",
        teoricos: ""
      }
    ],
    columns: [
      {
        label: "",
        field: "hours",
        sort: ""
      },
      {
        label: "LabGrad1",
        field: "labgrad1",
        sort: "labgrad1"
      },
      {
        label: "LabGrad2",
        field: "labgrad2",
        sort: "labgrad2"
      },
      {
        label: "LCEE",
        field: "lcee",
        sort: "lcee"
      },
      {
        label: "LabZorro",
        field: "labzorro",
        sort: "labzorro"
      },
      {
        label: "Auditório",
        field: "auditorio",
        sort: "auditorio"
      },
      {
        label: "Teóricos",
        field: "teoricos",
        sort: "teoricos"
      }
    ]
  };

  constructor(props) {
    super();
  }

  componentDidUpdate(prevProps, prevState) {
    if (prevProps.events !== this.props.events) {
      this.zerarTabela([...this.state.rows]);
      let compEventParts = this.clearEventPartsNotDay();
      this.popularTabela(compEventParts, [...this.state.rows]);
    }
  }

  zerarTabela(rows) {
    for (let i = 0; i < rows.length; i++) {
      rows[i]["labgrad1"] = "";
      rows[i]["labgrad2"] = "";
      rows[i]["lcee"] = "";
      rows[i]["labzorro"] = "";
      rows[i]["auditorio"] = "";
      rows[i]["teoricos"] = "";
    }
    this.setState({ rows: rows });
  }

  componentDidMount() {
    let compEventParts = this.clearEventPartsNotDay();
    this.popularTabela(compEventParts, [...this.state.rows]);
  }

  clearEventPartsNotDay() {
    let compEventParts = [];
    this.props.events.map(event => {
      return event.eventPart.map(part => {
        if (new Date(part.date).getDay() === this.props.day) {
          let aux = { title: event.title, type: event.type };
          compEventParts.push(Object.assign({}, part, aux));
        }
        return "";
      });
    });
    return compEventParts;
  }

  popularTabela(compEventParts, rows) {
    compEventParts.forEach(evePar => {
      let bufferEvents = 0;
      rows.forEach(row => {
        let hourEvent = new Date(evePar.date).getHours() + 3;
        let hourRow = Number.parseInt(row["hour"].split(":")[0]);
        if (hourEvent === hourRow) {
          row[evePar.local.toLocaleLowerCase()] = evePar.title;
          bufferEvents = evePar.duration - 1;
        } else if (bufferEvents > 0) {
          row[evePar.local.toLocaleLowerCase()] = evePar.title;
          bufferEvents--;
        }
      });
    });
    this.setState({ rows: [...rows] });
  }

  render() {
    return (
      <>
        <MDBTable responsive>
          <MDBTableHead columns={this.state.columns} />
          <MDBTableBody rows={this.state.rows} />
        </MDBTable>
      </>
    );
  }
}

export default Table;
