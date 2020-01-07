import React, { Component } from 'react';

import Container from 'react-bootstrap/Container';
import Table from 'react-bootstrap/Table';

import './tables.css';

class Tables extends Component {
    render() {
        return (
            <Container>
                <h3>Tabela</h3>
                <Table striped bordered hover responsive>
                    <thead>
                        <tr>
                            <th>Município</th>
                            <th>Estado</th>
                            <th>Sigla</th>
                        </tr>
                    </thead>
                    <tbody>
                        <tr>
                            <td>Maceió</td>
                            <td>Alagoas</td>
                            <td>AL</td>
                        </tr>
                        <tr>
                            <td>Curitiba</td>
                            <td>Santa Catarina</td>
                            <td>SC</td>
                        </tr>
                        <tr>
                            <td>João Pessoa</td>
                            <td>Paraíba</td>
                            <td>PB</td>
                        </tr>
                    </tbody>
                </Table>
            </Container>
        );
    }
}

export default Tables;
