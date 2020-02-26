import React from 'react';
import { MDBTable, MDBTableBody, MDBTableHead  } from 'mdbreact';
import Popovever from '../Popover/Popover';
import './table.css';

const Table = (props) => {
    const data = {
    columns: [
      {
        label: '',
        field: 'horarios',
        sort: ''
      },
      {
        label: 'LabGrad1',
        field: 'labgrad1',
        sort: 'labgrad1'
      },
      {
        label: 'LabGrad2',
        field: 'labgrad2',
        sort: 'labgrad2'
      },
      {
        label: 'LCEE',
        field: 'lcee',
        sort: 'lcee'
      },
      {
        label: 'LabZorro',
        field: 'labzorro',
        sort: 'labzorro'
      },
      {
        label: 'Auditório',
        field: 'auditorio',
        sort: 'auditorio'
      },
      {
        label: 'Teóricos',
        field: 'teoricos',
        sort: 'teoricos'
      }
    ],
    rows: [
      {
        'horarios': '7:00',
        'labgrad1': '',
        'labgrad2': '',
        'lcee': '',
        'labzorro': '',
        'auditorio': '',
        'teoricos': ''
      },
      {
        'horarios': '8:00',
        'labgrad1': '',
        'labgrad2': '',
        'lcee': '',
        'labzorro': '',
        'auditorio': '',
        'teoricos': ''
      },
      {
        'horarios': '9:00',
        'labgrad1': '',
        'labgrad2': '',
        'lcee': '',
        'labzorro': '',
        'auditorio': '',
        'teoricos': ''
      },
      {
        'horarios': '10:00',
        'labgrad1': '',
        'labgrad2': '',
        'lcee': '',
        'labzorro': '',
        'auditorio': '',
        'teoricos': ''
      },
      {
        'horarios': '11:00',
        'labgrad1': '',
        'labgrad2': '',
        'lcee': '',
        'labzorro': '',
        'auditorio': '',
        'teoricos': ''
      },
      {
        'horarios': '12:00',
        'labgrad1': '',
        'labgrad2': '',
        'lcee': '',
        'labzorro': '',
        'auditorio': '',
        'teoricos': ''
      },
      {
        'horarios': '13:00',
        'labgrad1': '',
        'labgrad2': '',
        'lcee': '',
        'labzorro': '',
        'auditorio': '',
        'teoricos': ''
      },
      {
        'horarios': '14:00',
        'labgrad1': '',
        'labgrad2': '',
        'lcee': '',
        'labzorro': '',
        'auditorio': '',
        'teoricos': ''
      },
      {
        'horarios': '15:00',
        'labgrad1': '',
        'labgrad2': '',
        'lcee': '',
        'labzorro': '',
        'auditorio': '',
        'teoricos': ''
      },
      {
        'horarios': '16:00',
        'labgrad1': '',
        'labgrad2': '',
        'lcee': '',
        'labzorro': '',
        'auditorio': '',
        'teoricos': ''
      },
      {
        'horarios': '17:00',
        'labgrad1': '',
        'labgrad2': '',
        'lcee': '',
        'labzorro': '',
        'auditorio': '',
        'teoricos': ''
      },
      {
        'horarios': '18:00',
        'labgrad1': '',
        'labgrad2': '',
        'lcee': '',
        'labzorro': '',
        'auditorio': '',
        'teoricos': ''
      }
    ]
  };

  let {eventos} = props;
  
  function montaPopover(evento){
    return(
      <Popovever name={evento.nome + " [" + evento.parte + "]"} type={evento.tipo} text={evento.descricao}/>
    );
  }

  function popularTabela(){
    data.rows.map(row => {
      eventos.map(evento =>{
        if(evento.lugar === 'labgrad1' && row.horarios === evento.inicio){
          row.labgrad1 = montaPopover(evento);
        }else if(evento.lugar === 'labgrad2' && row.horarios === evento.inicio){
          row.labgrad2 = montaPopover(evento);
        }else if(evento.lugar === 'lcee' && row.horarios === evento.inicio){
          row.lcee = montaPopover(evento);
        }else if(evento.lugar === 'labzorro' && row.horarios === evento.inicio){
          row.labzorro = montaPopover(evento);
        }else if(evento.lugar === 'auditorio' && row.horarios === evento.inicio){
          row.auditorio = montaPopover(evento);
        }else if(evento.lugar === 'teoricos' && row.horarios === evento.inicio){
          row.teoricos = montaPopover(evento);
        }
        return '';
      });
      return '';
    })

  }

  popularTabela();

  return (
    <MDBTable responsive>
      <MDBTableHead columns={data.columns}/>
      <MDBTableBody rows={data.rows} />
    </MDBTable>
  );
};

export default Table;