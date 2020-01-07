import React, { Component } from 'react';

import Card from 'react-bootstrap/Card';
import CardDeck from 'react-bootstrap/CardDeck';
import Container from 'react-bootstrap/Container';

import './home.css';

class Home extends Component {
    render() {
        return (
            <Container>
                <h3>Referências</h3>
                <CardDeck id="card-deck">
                    <Card>
                        <Card.Body>
                            <Card.Title>React Bootstrap</Card.Title>
                            <Card.Text>
                                <a href="https://react-bootstrap.github.io/">
                                    Link
                                </a>
                            </Card.Text>
                        </Card.Body>
                    </Card>
                    <Card>
                        <Card.Body>
                            <Card.Title>Bootstrap 4</Card.Title>
                            <Card.Text>
                                <a href="https://getbootstrap.com.br/docs/4.1/getting-started/introduction/">
                                    Link
                                </a>
                            </Card.Text>
                        </Card.Body>
                    </Card>
                    <Card>
                        <Card.Body>
                            <Card.Title>React Router</Card.Title>
                            <Card.Text>
                                <a href="https://medium.com/collabcode/roteamento-no-react-com-os-poderes-do-react-router-v4-fbc191b9937d">
                                    Link
                                </a>
                            </Card.Text>
                        </Card.Body>
                    </Card>
                </CardDeck>
            </Container>
        );
    }
}

export default Home;
