import React, { Component } from "react";
import {
    MDBNavbar, MDBNavbarNav, MDBNavItem, MDBNavLink, MDBNavbarToggler, MDBCollapse, MDBDropdown,
    MDBDropdownToggle, MDBDropdownMenu, MDBDropdownItem
} from "mdbreact";
import "./Nav.css"
import Login from "../Login/Login"

class Nav extends Component {
    state = {
        isOpen: false
    };

    toggleCollapse = () => {
        this.setState({ isOpen: !this.state.isOpen });
    }
    


    render() {
        return (
                <MDBNavbar color="grey lighten-5" expand="md"  fixed="top" scrolling >
                    <MDBNavbarToggler onClick={this.toggleCollapse} />
                    <MDBCollapse id="navbarCollapse3" isOpen={this.state.isOpen} navbar>
                        <MDBNavbarNav right>
                            <MDBNavItem active>
                                <MDBNavLink to="/" className="nav-links" >Início</MDBNavLink>
                            </MDBNavItem>
                            <MDBNavItem>
                                <MDBNavLink to="/about" className="nav-links">Quem Somos</MDBNavLink>
                            </MDBNavItem>
                            <MDBNavItem>
                                <MDBDropdown >
                                    <MDBDropdownToggle nav caret className="nav-links">
                                        <div className="d-none d-md-inline" >Projetos</div>
                                    </MDBDropdownToggle>
                                    <MDBDropdownMenu className="dropdown-default" >
                                        <MDBDropdownItem href="#!"><p className="dropDownItems">Topcom</p></MDBDropdownItem>
                                        <MDBDropdownItem href="#!"><p className="dropDownItems">Introcomp</p></MDBDropdownItem>
                                        <MDBDropdownItem href="#!"><p className="dropDownItems">Mobile</p></MDBDropdownItem>
                                        <MDBDropdownItem href="#!"><p className="dropDownItems">Web</p></MDBDropdownItem>
                                    </MDBDropdownMenu>
                                </MDBDropdown>
                            </MDBNavItem>
                            <MDBNavItem>
                                <MDBNavLink to="/documents" href="/documents" className="nav-links">Documentos</MDBNavLink>
                            </MDBNavItem>
                            <MDBNavItem>
                                <MDBNavLink to="/contact" className="nav-links">Contato</MDBNavLink>
                            </MDBNavItem>
                            <MDBNavItem>
                                <MDBNavLink to="/schedule" className="nav-links">Participe!</MDBNavLink>
                            </MDBNavItem>
                            <MDBNavItem>
                                <Login/>  
                            </MDBNavItem>
                        </MDBNavbarNav>
                    </MDBCollapse>
                </MDBNavbar>
        );
    }
}



export default Nav;