import React, { Component } from 'react';

import Button from 'react-bootstrap/Button';
import ButtonGroup from 'react-bootstrap/ButtonGroup';
import ButtonToolbar from 'react-bootstrap/ButtonToolbar';
import Container from 'react-bootstrap/Container';
import Dropdown from 'react-bootstrap/Dropdown';
import DropdownButton from 'react-bootstrap/DropdownButton';
import Row from 'react-bootstrap/Row';

import './buttons.css';

class Buttons extends Component {
    render() {
        return (
            <Container>
                <h3>Botão</h3>
                <Row className="justify-content-md-center">
                    <ButtonToolbar>
                        <Button variant="primary">Primary</Button>
                        <Button variant="secondary">Secondary</Button>
                        <Button variant="success">Success</Button>
                        <Button variant="warning">Warning</Button>
                        <Button variant="danger">Danger</Button>
                        <Button variant="info">Info</Button>
                        <Button variant="light">Light</Button>
                        <Button variant="dark">Dark</Button>
                        <Button variant="link">Link</Button>
                    </ButtonToolbar>
                </Row>
                <br/>
                <Row className="justify-content-md-center">
                    <ButtonGroup id="button-group">
                        <Button variant="secondary">Secondary</Button>
                        <Button variant="secondary">Secondary</Button>
                        <Button variant="secondary">Secondary</Button>
                    </ButtonGroup>
                </Row>
                <br/>
                <Row className="justify-content-md-center">
                    <ButtonToolbar>
                        <DropdownButton id="dropdown-basic-button" title="Dropdown button">
                            <Dropdown.Item href="#/action-1">Action</Dropdown.Item>
                            <Dropdown.Item href="#/action-2">Another action</Dropdown.Item>
                            <Dropdown.Item href="#/action-3">Something else</Dropdown.Item>
                        </DropdownButton>
                        <Dropdown as={ButtonGroup}>
                            <Button variant="success">Split Button</Button>

                            <Dropdown.Toggle split variant="success" id="dropdown-split-basic" />

                            <Dropdown.Menu>
                                <Dropdown.Item href="#/action-1">Action</Dropdown.Item>
                                <Dropdown.Item href="#/action-2">Another action</Dropdown.Item>
                                <Dropdown.Item href="#/action-3">Something else</Dropdown.Item>
                            </Dropdown.Menu>
                        </Dropdown>
                    </ButtonToolbar>
                </Row>
            </Container>
        );
    }
}

export default Buttons;
