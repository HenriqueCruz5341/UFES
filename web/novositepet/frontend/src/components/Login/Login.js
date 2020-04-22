import React, { Component } from 'react';
import { MDBContainer, MDBBtn, MDBModal, MDBModalBody,MDBNavLink,MDBIcon, MDBModalHeader, MDBModalFooter } from 'mdbreact';
import LoginForm from "./LoginForm/LoginForm"
import "./Login.css"

class Login extends Component {
state={
  modal: false,
}

toggle = () => {
  this.setState({
    modal: !this.state.modal
  });
}

render() {
  return (
    <MDBContainer>
      <MDBNavLink to="/schedule" className="nav-links"onClick={this.toggle}> <MDBIcon icon="user" />   Login</MDBNavLink>
      <MDBModal isOpen={this.state.modal} toggle={this.toggle}>
        <MDBModalHeader toggle={this.toggle}>Sign in</MDBModalHeader>
        <MDBModalBody>
            <LoginForm/>
        </MDBModalBody>
      </MDBModal>
    </MDBContainer>
    );
  }
}

export default Login;