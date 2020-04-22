import React, { Component, memo } from "react";
import {
  MDBTabPane,
  MDBTabContent,
  MDBNav,
  MDBNavItem,
  MDBNavLink
} from "mdbreact";
import Table from "../Table/Table";

class TabsDefault extends Component {
  state = {
    activeItem: "1"
  };

  toggle = tab => e => {
    if (this.state.activeItem !== tab) {
      this.setState({
        activeItem: tab
      });
    }
  };

  constructor(props) {
    super();
  }

  render() {
    return (
      <>
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
            <Table events={this.props.events} day={1} />
          </MDBTabPane>
          <MDBTabPane tabId="2" role="tabpanel">
            <Table events={this.props.events} day={2} />
          </MDBTabPane>
          <MDBTabPane tabId="3" role="tabpanel">
            <Table events={this.props.events} day={3} />
          </MDBTabPane>
          <MDBTabPane tabId="4" role="tabpanel">
            <Table events={this.props.events} day={4} />
          </MDBTabPane>
          <MDBTabPane tabId="5" role="tabpanel">
            <Table events={this.props.events} day={5} />
          </MDBTabPane>
        </MDBTabContent>
      </>
    );
  }
}
export default memo(TabsDefault);
