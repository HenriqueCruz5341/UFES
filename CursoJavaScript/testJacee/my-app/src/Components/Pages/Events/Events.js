import React, { Component } from 'react';
import eventosImg from '../../../assets/img/eventos.png';
import {MDBMask, MDBView, MDBCol, MDBContainer} from 'mdbreact';
import './events.css';
import EventList from '../../Main/EventList/EventList';

class Events extends React.Component {

  constructor(){
    super();
    this.state = {
      search: ''
    };
  }

  updateSearch(event){
    this.setState({search: event.target.value.substr(0,20)});
  }

  render(){
    let eventos = [
        {
          id: 'event1',
          nome: 'Aprendendo C',
          inicio: '10:00',
          dia: 'segunda',
          lugar: 'labgrad1',
          tipo: 'minicurso',
          descricao: 'Aprenda os fundamentos básicos de C' ,
          responsavel: 'Thiago'
        },
        {
          id: 'event2',
          nome: 'Aprendendo JAVA',
          inicio: '7:00',
          dia: 'segunda',
          lugar: 'labgrad2',
          tipo: 'workshop',
          descricao: 'Aprenda os fundamentos básicos de JAVA' ,
          responsavel: 'Lucca'
        },
        {
          id: 'event3',
          nome: 'Aprendendo Unity',
          inicio: '8:00',
          dia: 'segunda',
          lugar: 'labgrad1',
          tipo: 'minicurso',
          descricao: 'Aprenda os fundamentos básicos de Unity' ,
          responsavel: 'Thiebersom'
        },
        {
          id: 'event4',
          nome: 'Machine Learning',
          inicio: '10:00',
          dia: 'segunda',
          lugar: 'auditorio',
          tipo: 'palestra',
          descricao: 'Veja as tecnologias mais usadas na área de Machine Learning' ,
          responsavel: 'André'
        },
        {
          id: 'event5',
          nome: 'Aprendendo Eagle',
          inicio: '11:00',
          dia: 'segunda',
          lugar: 'lcee',
          tipo: 'minicurso',
          descricao: 'Aprenda a criar suas primeiras placas de circuitos com Eagle' ,
          responsavel: 'PetEletrica'
        }
    ];

    let filteredEvents = eventos.filter(
      (evento) => {
        return (evento.nome.toLocaleLowerCase().indexOf(this.state.search) !== -1) || (evento.descricao.toLocaleLowerCase().indexOf(this.state.search) !== -1);
      }
    );

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

        <MDBContainer>
            <MDBCol md="12">
              <form className="form-inline mt-4 mb-4">
                <input className="form-control form-control-md ml-2 w-100" type="text" placeholder="Search" aria-label="Search" 
                  value={this.state.search} onChange={this.updateSearch.bind(this)}/>
              </form>
            </MDBCol> 

          <EventList eventos={filteredEvents}/>
        </MDBContainer>
      </div>
    );
  }
}

export default Events;
