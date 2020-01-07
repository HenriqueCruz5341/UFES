import React, { Component } from 'react';

import Col from 'react-bootstrap/Col';
import Container from 'react-bootstrap/Container';
import Image from 'react-bootstrap/Image';
import Row from 'react-bootstrap/Row';

import adriana from '../../resources/adriana.jpg';
import candice from '../../resources/candice.jpg';
import gisele from '../../resources/gisele.jpg';

import './images.css';

class Images extends Component {
    render() {
        return (
            <Container>
                <h3>Imagem</h3>
                <Row>
                    <Col xs={6} md={4}>
                        <Image id="img" src={candice} rounded />
                    </Col>
                    <Col xs={6} md={4}>
                        <Image id="img" src={adriana} roundedCircle />
                    </Col>
                    <Col xs={6} md={4}>
                        <Image id="img" src={gisele} thumbnail />
                    </Col>
                </Row>
            </Container>
        );
    }
}

export default Images;
