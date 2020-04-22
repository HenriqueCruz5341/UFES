import React, { Component } from "react";
import {
  MDBContainer,
  MDBTabPane,
  MDBTabContent,
  MDBNav,
  MDBNavItem,
  MDBNavLink
} from "mdbreact";
import api from "../../../../services/api";
import Table from "../Table/Table";

class TabSchedule extends Component {
  state = {
    activeItem: "1",
    events: false
  };

  toggle = tab => e => {
    if (this.state.activeItem !== tab) {
      this.setState({
        activeItem: tab
      });
    }
  };

  async getEvents() {
    try {
      const response = await api.get("/api/event/");
      this.setState({ events: response.data.events });
    } catch (err) {
      console.log(err.response);
    }
  }

  filterEvents(day) {
    return this.state.events.filter(event => {
      let correctDay = false;
      event.eventPart.map(part => {
        if (new Date(part.date).getDay() === day) {
          return (correctDay = true);
        }
        return correctDay;
      });
      return correctDay;
    });
  }

  componentDidMount() {
    this.getEvents();
  }

  render() {
    return (
      <MDBContainer>
        <MDBNav className="nav-tabs mt-5">
          <MDBNavItem>
            <MDBNavLink
              link
              to="#"
              active={this.state.activeItem === "1"}
              onClick={this.toggle("1")}
              role="tab"
            >
              Segunda
            </MDBNavLink>
          </MDBNavItem>
          <MDBNavItem>
            <MDBNavLink
              link
              to="#"
              active={this.state.activeItem === "2"}
              onClick={this.toggle("2")}
              role="tab"
            >
              Terça
            </MDBNavLink>
          </MDBNavItem>
          <MDBNavItem>
            <MDBNavLink
              link
              to="#"
              active={this.state.activeItem === "3"}
              onClick={this.toggle("3")}
              role="tab"
            >
              Quarta
            </MDBNavLink>
          </MDBNavItem>
          <MDBNavItem>
            <MDBNavLink
              link
              to="#"
              active={this.state.activeItem === "4"}
              onClick={this.toggle("4")}
              role="tab"
            >
              Quinta
            </MDBNavLink>
          </MDBNavItem>
          <MDBNavItem>
            <MDBNavLink
              link
              to="#"
              active={this.state.activeItem === "5"}
              onClick={this.toggle("5")}
              role="tab"
            >
              Sexta
            </MDBNavLink>
          </MDBNavItem>
        </MDBNav>
        <MDBTabContent activeItem={this.state.activeItem}>
          <MDBTabPane tabId="1" role="tabpanel">
            {!this.state.events ? (
              <span>Carregando...</span>
            ) : (
              <Table events={this.filterEvents(1)} day={1} />
            )}
          </MDBTabPane>
          <MDBTabPane tabId="2" role="tabpanel">
            {!this.state.events ? (
              <span>Carregando...</span>
            ) : (
              <Table events={this.filterEvents(2)} day={2} />
            )}
          </MDBTabPane>
          <MDBTabPane tabId="3" role="tabpanel">
            {!this.state.events ? (
              <span>Carregando...</span>
            ) : (
              <Table events={this.filterEvents(3)} day={3} />
            )}
          </MDBTabPane>
          <MDBTabPane tabId="4" role="tabpanel">
            {!this.state.events ? (
              <span>Carregando...</span>
            ) : (
              <Table events={this.filterEvents(4)} day={4} />
            )}
          </MDBTabPane>
          <MDBTabPane tabId="5" role="tabpanel">
            {!this.state.events ? (
              <span>Carregando...</span>
            ) : (
              <Table events={this.filterEvents(5)} day={5} />
            )}
          </MDBTabPane>
        </MDBTabContent>
      </MDBContainer>
    );
  }
}
export default TabSchedule;
