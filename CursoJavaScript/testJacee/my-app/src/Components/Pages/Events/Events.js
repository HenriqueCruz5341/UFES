import React from 'react';
import eventosImg from '../../../assets/img/eventos.png';
import {MDBMask, MDBView} from 'mdbreact';
import './events.css';
import EventList from '../../Main/EventList/EventList';

function Events() {

    let eventos = [
        {
          nome: 'Aprendendo C',
          inicio: '10:00',
          dia: 'segunda',
          lugar: 'labgrad1',
          tipo: 'minicurso',
          descricao: 'Aprenda os fundamentos básicos de C' ,
          responsavel: 'Thiago'
        },
        {
          nome: 'Aprendendo JAVA',
          inicio: '7:00',
          dia: 'segunda',
          lugar: 'labgrad2',
          tipo: 'workshop',
          descricao: 'Aprenda os fundamentos básicos de JAVA' ,
          responsavel: 'Lucca'
        },
        {
          nome: 'Aprendendo Unity',
          inicio: '8:00',
          dia: 'segunda',
          lugar: 'labgrad1',
          tipo: 'minicurso',
          descricao: 'Aprenda os fundamentos básicos de Unity' ,
          responsavel: 'Thiebersom'
        },
        {
          nome: 'Machine Learning',
          inicio: '10:00',
          dia: 'segunda',
          lugar: 'auditorio',
          tipo: 'palestra',
          descricao: 'Veja as tecnologias mais usadas na área de Machine Learning' ,
          responsavel: 'André'
        },
        {
          nome: 'Aprendendo Eagle',
          inicio: '11:00',
          dia: 'segunda',
          lugar: 'lcee',
          tipo: 'minicurso',
          descricao: 'Aprenda a criar suas primeiras placas de circuitos com Eagle' ,
          responsavel: 'PetEletrica'
        }
      ];

  return (
    <div className="events" style={{paddingTop: "100px"}}>
      <MDBView className="titlePage">
        <img
          src={eventosImg}
          className="img-fluid eventos"
          alt="eventos"

        />
        <MDBMask overlay="black-strong" className="flex-center">
            <h1 className="white-text">Eventos</h1>
          </MDBMask>
      </MDBView>
      <EventList eventos={eventos}/>
    </div>
  );
}

export default Events;
