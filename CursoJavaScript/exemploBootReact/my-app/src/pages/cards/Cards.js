import React, { Component } from 'react';

import Card from 'react-bootstrap/Card';
import CardDeck from 'react-bootstrap/CardDeck';
import Container from 'react-bootstrap/Container';

import coral from '../../resources/coral.jpg';
import mamba from '../../resources/mamba.jpg';
import naja from '../../resources/naja.jpg';

import './cards.css';

class Cards extends Component {
    render() {
        return (
            <Container>
                <h3>Cartão</h3>
                <CardDeck id="card-deck">
                    <Card>
                        <Card.Img variant="top" src={coral} />
                        <Card.Body>
                            <Card.Title>Cobra Coral</Card.Title>
                            <Card.Text>
                                This is a wider card with supporting text below as a natural lead-in to
                                additional content. This content is a little bit longer.
                                </Card.Text>
                        </Card.Body>
                    </Card>
                    <Card>
                        <Card.Img variant="top" src={mamba}/>
                        <Card.Body>
                            <Card.Title>Mamba Negra</Card.Title>
                            <Card.Text>
                                This card has supporting text below as a natural lead-in to additional
                                    content.{' '}
                            </Card.Text>
                        </Card.Body>
                    </Card>
                    <Card>
                        <Card.Img variant="top" src={naja} />
                        <Card.Body>
                            <Card.Title>Cobra Naja</Card.Title>
                            <Card.Text>
                                This is a wider card with supporting text below as a natural lead-in to
                                additional content. This card has even longer content than the first to
                                show that equal height action.
                                </Card.Text>
                        </Card.Body>
                    </Card>
                </CardDeck>
            </Container>
        );
    }
}

export default Cards;
