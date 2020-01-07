import React, { Component } from 'react';
import { BrowserRouter as Router, Route, Switch } from 'react-router-dom';

import Nav from 'react-bootstrap/Nav';
import Navbar from 'react-bootstrap/Navbar';

import ButtonPage from './pages/buttons/Buttons';
import CardPage from './pages/cards/Cards';
import CarouselPage from './pages/carousels/Carousels';
import FormPage from './pages/forms/Forms';
import GridPage from './pages/grids/Grids';
import HomePage from './pages/home/Home';
import ImagePage from './pages/images/Images';
import NavbarPage from './pages/navbars/Navbars';
import TablePage from './pages/tables/Tables';

import logo from './logo.svg';

import 'bootstrap/dist/css/bootstrap.min.css';
import './App.css';

class App extends Component {
    render() {
        return (
            <Router>
                <Navbar expand="lg" bg="dark" variant="dark">
                    <Navbar.Brand href="/home">
                        <img
                            alt=""
                            src={logo}
                            width="30"
                            height="30"
                            className="d-inline-block align-top"
                        />{' '}
                        PWEB2: React
                    </Navbar.Brand>
                    <Navbar.Toggle aria-controls="responsive-navbar-nav" />
                    <Navbar.Collapse id="responsive-navbar-nav">
                        <Nav className="mr-auto">
                            <Nav.Link href="/navbar">Barra de Navegação</Nav.Link>
                            <Nav.Link href="/button">Botão</Nav.Link>
                            <Nav.Link href="/card">Cartão</Nav.Link>
                            <Nav.Link href="/carousel">Carrossel</Nav.Link>
                            <Nav.Link href="/form">Formulário</Nav.Link>
                            <Nav.Link href="/grid">Grade</Nav.Link>
                            <Nav.Link href="/image">Imagem</Nav.Link>
                            <Nav.Link href="/table">Tabela</Nav.Link>                           
                        </Nav>
                    </Navbar.Collapse>
                </Navbar>
                <Switch>
                    <Route path="/" exact={true} component={HomePage}/>
                    <Route path="/home" component={HomePage}/>
                    <Route path="/navbar" component={NavbarPage}/>
                    <Route path="/button" component={ButtonPage}/>
                    <Route path="/card" component={CardPage}/>
                    <Route path="/carousel" component={CarouselPage}/>
                    <Route path="/form" component={FormPage}/>
                    <Route path="/grid" component={GridPage}/>
                    <Route path="/image" component={ImagePage}/>
                    <Route path="/table" component={TablePage}/>
                </Switch>
            </Router>
        );
    }
}

export default App;
