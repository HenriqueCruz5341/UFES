import React, { Component } from "react";
import {
MDBNavbar, MDBNavbarBrand, MDBNavbarNav, MDBNavItem, MDBNavLink, MDBNavbarToggler, MDBCollapse, MDBIcon,
MDBDropdown, MDBDropdownToggle, MDBDropdownMenu, MDBDropdownItem
} from "mdbreact";
import logoJacee from '../../../assets/img/JACEE.png';

class NavbarPage extends Component {
    state = {
        isOpen: false
    };

    toggleCollapse = () => {
        this.setState({ isOpen: !this.state.isOpen });
    }

    render() {
        return (
                <MDBNavbar color="grey lighten-3" light expand="md" fixed="top" scrolling>
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
        );
    }
}

export default NavbarPage;