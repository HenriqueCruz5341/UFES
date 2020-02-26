import React, { Component } from "react";
import { MDBBtn, MDBCollapse, MDBIcon } from "mdbreact";

class CollapseEvent extends Component {
state = {
  collapseID: ""
}

constructor(props){
  super();
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
      color="primary"
      onClick={this.toggleCollapse("basicCollapse")}
      style={{ marginBottom: "1rem" }}
    >
      <MDBIcon icon="plus" />
    </MDBBtn>
        <MDBCollapse id="basicCollapse" isOpen={this.state.collapseID}>
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
        </MDBCollapse>
      </>
    );
  }
}

export default CollapseEvent;