import React from "react";
import { BrowserRouter as Router } from "react-router-dom";
import {
  MDBNavbar,
  MDBNavbarBrand,
  MDBNavbarNav,
  MDBNavItem,
  MDBNavLink,
  MDBNavbarToggler,
  MDBCollapse,
  MDBIcon,
  MDBDropdown, MDBDropdownToggle, MDBDropdownMenu, MDBDropdownItem
} from "mdbreact";
import "./navBarImage.css";
import logoJacee from '../../../assets/img/JACEE.png';

class NavBarImage extends React.Component {
    state = {
        isOpen: false
    };

    toggleCollapse = () => {
        this.setState({ isOpen: !this.state.isOpen });
    }

    render() {
        const overlay = (
        <div
            id="sidenav-overlay"
            style={{ backgroundColor: "transparent" }}
            onClick={this.handleTogglerClick}
        />
        );
    return (
      <div id="navBarImage">
        <Router>
          <div>
          <MDBNavbar color="grey lighten-3" light expand="md" fixed="top" scrolling transparent>
                    <MDBNavbarBrand>
                        <MDBNavLink to="/">
                            <img
                                src={logoJacee}
                                alt="Inicio"
                            />
                            </MDBNavLink>
                    </MDBNavbarBrand>
                    <MDBNavbarToggler onClick={this.toggleCollapse} />
                    <MDBCollapse id="navbarCollapse3" isOpen={this.state.isOpen} navbar>
                    <MDBNavbarNav left>
                        <MDBNavItem>
                        <MDBNavLink to="sobre">Sobre</MDBNavLink>
                        </MDBNavItem>
                        <MDBNavItem>
                        <MDBNavLink to="certificados">Certificados</MDBNavLink>
                        </MDBNavItem>
                        <MDBNavItem>
                        <MDBNavLink to="fotos">Fotos</MDBNavLink>
                        </MDBNavItem>
                        <MDBNavItem>
                        <MDBNavLink to="faq">FAQ</MDBNavLink>
                        </MDBNavItem>
                        <MDBNavItem>
                        <MDBNavLink to="/cronograma">Cronograma</MDBNavLink>
                        </MDBNavItem>
                        <MDBNavItem>
                        <MDBNavLink to="/eventos">Eventos</MDBNavLink>
                        </MDBNavItem>
                    </MDBNavbarNav>
                    <MDBNavbarNav right>
                    <MDBNavItem>
                    <MDBDropdown>
                        <MDBDropdownToggle nav caret>
                        <MDBIcon icon="user" />
                        </MDBDropdownToggle>
                        <MDBDropdownMenu className="dropdown-default">
                        <MDBDropdownItem href="#!">Login</MDBDropdownItem>
                        <MDBDropdownItem href="#!">Cadastrar-se</MDBDropdownItem>
                        </MDBDropdownMenu>
                    </MDBDropdown>
                        </MDBNavItem>
                    </MDBNavbarNav>
                    </MDBCollapse>
                </MDBNavbar>
            {this.state.collapsed && overlay}
          </div>
        </Router>
      </div>
    );
  }
}

export default NavBarImage;