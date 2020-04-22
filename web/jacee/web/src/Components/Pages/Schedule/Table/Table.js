import React, { Component } from "react";
import { MDBTable, MDBTableBody, MDBTableHead } from "mdbreact";
import Popovever from "../Popover/Popover";
import { Th, Td } from "./style";

class Table extends Component {
  state = {
    columns: [
      {
        label: "",
        field: "hour",
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
    ],
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
        labgrad1: "Almoço",
        labgrad2: "Almoço",
        lcee: "Almoço",
        labzorro: "Almoço",
        auditorio: "Almoço",
        teoricos: "Almoço"
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
    ]
  };

  constructor(props) {
    super();
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

  montaPopover = (event, rowContent) => {
    return (
      <div>
        <Popovever name={event.title} type={event.type} />
        {rowContent}
      </div>
    );
  };

  popularTabela(compEventParts, rows) {
    compEventParts.forEach(evePar => {
      let bufferEvents = 0;
      rows.forEach(row => {
        let hourEvent = new Date(evePar.date).getHours() + 3;
        let hourRow = Number.parseInt(row["hour"].split(":")[0]);
        if (hourEvent === hourRow) {
          row[evePar.local.toLocaleLowerCase()] = this.montaPopover(
            evePar,
            row[evePar.local.toLocaleLowerCase()]
          );
          bufferEvents = evePar.duration - 1;
        } else if (bufferEvents > 0) {
          row[evePar.local.toLocaleLowerCase()] = this.montaPopover(
            evePar,
            row[evePar.local.toLocaleLowerCase()]
          );
          bufferEvents--;
        }
      });
    });

    this.setState({ rows: [...rows] });
  }

  render() {
    return (
      <>
        <MDBTable bordered responsive>
          <MDBTableHead>
            <tr>
              {this.state.columns.map((col, index) => (
                <Th key={col.field + index.toString()} field={col.field}>
                  {col.label}
                </Th>
              ))}
            </tr>
          </MDBTableHead>
          <MDBTableBody>
            {this.state.rows.map((row, index) => (
              <tr key={row.field + index.toString()}>
                {this.state.columns.map((col, index) => {
                  return (
                    <Td
                      key={col.field + index.toString()}
                      data_col={col.field + index.toString()}
                    >
                      {row[col.field]}
                    </Td>
                  );
                })}
              </tr>
            ))}
          </MDBTableBody>
        </MDBTable>
      </>
    );
  }
}

export default Table;
