import React, { Component } from "react";
import {
  MDBNavbar,
  MDBNavbarBrand,
  MDBNavbarNav,
  MDBNavItem,
  MDBNavbarToggler,
  MDBCollapse,
  MDBIcon,
  MDBDropdown,
  MDBDropdownMenu,
} from "mdbreact";
import {
  MDBNavLinkLogo,
  MDBNavLinkS,
  MDBDropdownToggleS,
  MDBDropdownItemS,
} from "./style";
import logoJacee from "../../../assets/img/JACEE_gray.png";
import ModalRegisterStudent from "../ModalRegister/ModalRegisterStudent";
import ModalLogin from "../ModalLogin/ModalLogin";
import isAuth from "../../../services/Auth";

class NavbarPage extends Component {
  state = {
    isOpen: false,
    modalLogin: false,
    modalRegisterStudent: false,
  };

  toggleCollapse = () => {
    this.setState({ isOpen: !this.state.isOpen });
  };

  toggleModalLogin = () => {
    this.setState({
      modalLogin: !this.state.modalLogin,
    });
  };

  toggleModalRegisterStudent = () => {
    this.setState({
      modalRegisterStudent: !this.state.modalRegisterStudent,
    });
  };

  showOptions() {
    let auth = isAuth();
    if (auth) {
      return (
        <>
          <MDBNavbarNav right>
            <MDBNavItem>
              <MDBNavLinkS to="/studentsAdmin">Estudantes</MDBNavLinkS>
            </MDBNavItem>
            <MDBNavItem>
              <MDBNavLinkS to="/eventsAdmin">Eventos</MDBNavLinkS>
            </MDBNavItem>
            <MDBNavItem>
              <MDBNavLinkS to="/adminsList">Administradores</MDBNavLinkS>
            </MDBNavItem>
            <MDBNavItem>
              <MDBNavLinkS to="/markPresence">Marcar Presença</MDBNavLinkS>
            </MDBNavItem>
            <MDBNavItem>
              <MDBNavLinkS to="/logout">Sair</MDBNavLinkS>
            </MDBNavItem>
          </MDBNavbarNav>
        </>
      );
    } else {
      return (
        <MDBNavbarNav right>
          <MDBNavItem>
            <MDBNavLinkS to="/sobre">Sobre</MDBNavLinkS>
          </MDBNavItem>
          <MDBNavItem>
            <MDBNavLinkS to="/certificados">Certificados</MDBNavLinkS>
          </MDBNavItem>
          <MDBNavItem>
            <MDBNavLinkS to="/fotos">Fotos</MDBNavLinkS>
          </MDBNavItem>
          <MDBNavItem>
            <MDBNavLinkS to="/faq">FAQ</MDBNavLinkS>
          </MDBNavItem>
          <MDBNavItem>
            <MDBNavLinkS to="/cronograma">Cronograma</MDBNavLinkS>
          </MDBNavItem>
          <MDBNavItem>
            <MDBNavLinkS to="/eventos">Eventos</MDBNavLinkS>
          </MDBNavItem>
          {auth === null ? (
            <MDBNavItem>
              <MDBDropdown>
                <MDBDropdownToggleS nav caret>
                  <MDBIcon icon="user" />
                </MDBDropdownToggleS>
                <MDBDropdownMenu className="dropdown-default">
                  <MDBDropdownItemS onClick={this.toggleModalLogin}>
                    Login
                  </MDBDropdownItemS>
                  <MDBDropdownItemS onClick={this.toggleModalRegisterStudent}>
                    Cadastre-se
                  </MDBDropdownItemS>
                </MDBDropdownMenu>
              </MDBDropdown>
            </MDBNavItem>
          ) : (
            <>
              <MDBNavItem>
                <MDBNavLinkS to="/perfil">Minha Conta</MDBNavLinkS>
              </MDBNavItem>
              <MDBNavItem>
                <MDBNavLinkS to="/logout">Sair</MDBNavLinkS>
              </MDBNavItem>
            </>
          )}
        </MDBNavbarNav>
      );
    }
  }

  render() {
    return (
      <MDBNavbar
        light
        expand="md"
        fixed="top"
        scrolling
        style={{ background: "#fff", zIndex: "999" }}
      >
        <MDBNavbarBrand>
          <MDBNavLinkLogo to="/">
            <img src={logoJacee} width="40px" height="40px" alt="Inicio" />
          </MDBNavLinkLogo>
        </MDBNavbarBrand>
        <MDBNavbarToggler onClick={this.toggleCollapse} />
        <MDBCollapse id="navbarCollapse3" isOpen={this.state.isOpen} navbar>
          {this.showOptions()}
        </MDBCollapse>

        <ModalRegisterStudent
          toggleModalRegisterStudent={this.toggleModalRegisterStudent}
          stateModal={this.state.modalRegisterStudent}
        />
        <ModalLogin
          isLoged={this.login}
          toggleModalLogin={this.toggleModalLogin}
          stateModal={this.state.modalLogin}
        />
      </MDBNavbar>
    );
  }
}

export default NavbarPage;
