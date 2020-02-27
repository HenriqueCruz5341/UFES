import React, { Component } from "react";
import { MDBBtn, MDBCollapse, MDBIcon, MDBContainer } from "mdbreact";
import './collapseEvent.css';

class CollapseEvent extends Component {
state = {
  collapseID: ""
}

constructor(props){
  super();
  this.state = {
    icone: <MDBIcon icon="angle-down" />
  };
}

toggleCollapse = collapseID => () => {
  this.setState(prevState => ({
    collapseID: prevState.collapseID !== collapseID ? collapseID : ""
  }));
}

render() {
  let {evento} = this.props;

  return (
      <>
    <MDBBtn
      color="mdb-color"
      onClick={this.toggleCollapse("basicCollapse")}
      style={{ marginBottom: "1rem" }, {width: '100%'}}
    >
      <div className='conteudoBotao'>
        <strong>{evento.nome}</strong>
        <div className={evento.id + ' iconesBotao'}>
          {this.state.icone}
        </div>
      </div>
    </MDBBtn>
        <MDBCollapse className='conteudoCollapse' onOpened={() => this.setState({icone: <MDBIcon icon="angle-up" />})} 
          onClosed={() => this.setState({icone: <MDBIcon icon="angle-down" />})} id="basicCollapse" isOpen={this.state.collapseID}>
          <MDBContainer>  
            <p>
              Tipo: {evento.tipo}
            </p>
            <p>
                Responsável: {evento.responsavel}
            </p>
            <p>
                Data: {evento.inicio} - {evento.dia} - {evento.lugar}
            </p>
            <p>
                Descrição: {evento.descricao}
            </p>
          </MDBContainer>
        </MDBCollapse>
      </>
    );
  }
}

export default CollapseEvent;