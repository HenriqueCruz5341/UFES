import React, { Component } from 'react';

import Col from 'react-bootstrap/Col';
import Container from 'react-bootstrap/Container';
import Image from 'react-bootstrap/Image';
import Row from 'react-bootstrap/Row';

import dog1 from '../../resources/dog1.jpg';
import dog2 from '../../resources/dog2.jpg';
import cat1 from '../../resources/cat1.jpg';
import cat2 from '../../resources/cat2.jpg';
import cat3 from '../../resources/cat3.jpg';

import './grids.css';

class Grids extends Component {
    render() {
        return (
            <Container>
                <h3>Grade</h3>
                <Row>
                    <Col>
                        <Image id="img" src={cat1} />
                    </Col>
                    <Col>
                        <Image id="img" src={cat2} />
                    </Col>
                    <Col>
                        <Image id="img" src={cat3} />
                    </Col>
                </Row>
                <br/>
                <Row>
                    <Col>
                        <Image id="img" src={dog1} />
                    </Col>
                    <Col>
                        <Image id="img" src={dog2} />
                    </Col>
                </Row>
            </Container>
        );
    }
}

export default Grids;
