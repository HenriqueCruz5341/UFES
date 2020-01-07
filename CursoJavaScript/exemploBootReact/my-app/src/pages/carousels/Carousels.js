import React, { Component } from 'react';

import Carousel from 'react-bootstrap/Carousel';
import Container from 'react-bootstrap/Container';
import Row from 'react-bootstrap/Row';

import autumn from '../../resources/autumn.jpg';
import spring from '../../resources/spring.jpg';
import summer from '../../resources/summer.jpg';
import winter from '../../resources/winter.jpg';

import './carousels.css';

class Carousels extends Component {
    render() {
        return (
            <Container>
                <h3>Carrossel</h3>
                <Row className="justify-content-md-center">
                    <Carousel id="carousel">
                        <Carousel.Item>
                            <img
                                className="d-block w-100"
                                src={summer}
                                alt="Summer"
                            />
                            <Carousel.Caption>
                                <h3>Verão</h3>
                            </Carousel.Caption>
                        </Carousel.Item>
                        <Carousel.Item>
                            <img
                                className="d-block w-100"
                                src={autumn}
                                alt="Autumn"
                            />
                            <Carousel.Caption>
                                <h3>Outono</h3>
                            </Carousel.Caption>
                        </Carousel.Item>
                        <Carousel.Item>
                            <img
                                className="d-block w-100"
                                src={winter}
                                alt="Winter"
                            />
                            <Carousel.Caption>
                                <h3>Inverno</h3>
                            </Carousel.Caption>
                        </Carousel.Item>
                        <Carousel.Item>
                            <img
                                className="d-block w-100"
                                src={spring}
                                alt="Spring"
                            />
                            <Carousel.Caption>
                                <h3>Primavera</h3>
                            </Carousel.Caption>
                        </Carousel.Item>
                    </Carousel>
                </Row>
            </Container>
        );
    }
}

export default Carousels;
