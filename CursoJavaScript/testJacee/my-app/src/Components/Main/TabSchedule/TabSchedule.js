import React, { Component } from "react";
import { MDBContainer, MDBTabPane, MDBTabContent, MDBNav, MDBNavItem, MDBNavLink } from "mdbreact";
import Table from "../Table/Table";

  class TabSchedule extends Component {
    state = {
      activeItem: "1"
    };

    toggle = tab => e => {
      if (this.state.activeItem !== tab) {
        this.setState({
          activeItem: tab
        });
      }
    };

    render() {

      let eventos = [
        {
          nome: 'Aprendendo C',
          inicio: '10:00',
          parte: '1/3',
          dia: 'segunda',
          lugar: 'labgrad1',
          tipo: 'minicurso',
          descricao: 'Aprenda os fundamentos básicos de C' 
        },
        {
          nome: 'Aprendendo C',
          inicio: '11:00',
          parte: '2/3',
          dia: 'segunda',
          lugar: 'labgrad1',
          tipo: 'minicurso',
          descricao: 'Aprenda os fundamentos básicos de C' 
        },
        {
          nome: 'Aprendendo C',
          inicio: '8:00',
          parte: '3/3',
          dia: 'terca',
          lugar: 'labgrad1',
          tipo: 'minicurso',
          descricao: 'Aprenda os fundamentos básicos de C' 
        },
        {
          nome: 'Aprendendo JAVA',
          inicio: '7:00',
          parte: '1/4',
          dia: 'segunda',
          lugar: 'labgrad2',
          tipo: 'workshop',
          descricao: 'Aprenda os fundamentos básicos de JAVA' 
        },
        {
          nome: 'Aprendendo JAVA',
          inicio: '8:00',
          parte: '2/4',
          dia: 'segunda',
          lugar: 'labzorro',
          tipo: 'workshop',
          descricao: 'Aprenda os fundamentos básicos de JAVA' 
        },
        {
          nome: 'Aprendendo JAVA',
          inicio: '13:00',
          parte: '3/4',
          dia: 'segunda',
          lugar: 'labgrad2',
          tipo: 'workshop',
          descricao: 'Aprenda os fundamentos básicos de JAVA' 
        },
        {
          nome: 'Aprendendo JAVA',
          inicio: '14:00',
          parte: '4/4',
          dia: 'segunda',
          lugar: 'labgrad2',
          tipo: 'workshop',
          descricao: 'Aprenda os fundamentos básicos de JAVA' 
        },
        {
          nome: 'Aprendendo Unity',
          inicio: '8:00',
          parte: '1/2',
          dia: 'segunda',
          lugar: 'labgrad1',
          tipo: 'minicurso',
          descricao: 'Aprenda os fundamentos básicos de Unity' 
        },
        {
          nome: 'Aprendendo Unity',
          inicio: '9:00',
          parte: '2/2',
          dia: 'segunda',
          lugar: 'labzorro',
          tipo: 'minicurso',
          descricao: 'Aprenda os fundamentos básicos de Unity' 
        },
        {
          nome: 'Machine Learning',
          inicio: '10:00',
          parte: '1/2',
          dia: 'segunda',
          lugar: 'auditorio',
          tipo: 'palestra',
          descricao: 'Veja as tecnologias mais usadas na área de Machine Learning' 
        },
        {
          nome: 'Machine Learning',
          inicio: '11:00',
          parte: '2/2',
          dia: 'segunda',
          lugar: 'auditorio',
          tipo: 'palestra',
          descricao: 'Veja as tecnologias mais usadas na área de Machine Learning' 
        },
        {
          nome: 'Aprendendo Eagle',
          inicio: '11:00',
          parte: '2/2',
          dia: 'segunda',
          lugar: 'lcee',
          tipo: 'minicurso',
          descricao: 'Aprenda a criar suas primeiras placas de circuitos com Eagle' 
        },
        {
          nome: 'Aprendendo Eagle',
          inicio: '12:00',
          parte: '2/2',
          dia: 'segunda',
          lugar: 'lcee',
          tipo: 'minicurso',
          descricao: 'Aprenda a criar suas primeiras placas de circuitos com Eagle' 
        }
      ];

      return (
        <MDBContainer>
        <MDBNav className="nav-tabs mt-5">
          <MDBNavItem>
            <MDBNavLink to="#" active={this.state.activeItem === "1"} onClick={this.toggle("1")} role="tab" >
              Segunda
            </MDBNavLink>
          </MDBNavItem>
          <MDBNavItem>
            <MDBNavLink to="#" active={this.state.activeItem === "2"} onClick={this.toggle("2")} role="tab" >
              Profile
            </MDBNavLink>
          </MDBNavItem>
          <MDBNavItem>
            <MDBNavLink to="#" active={this.state.activeItem === "3"} onClick={this.toggle("3")} role="tab" >
              Profile
            </MDBNavLink>
          </MDBNavItem>
        </MDBNav>
        <MDBTabContent activeItem={this.state.activeItem} >
          <MDBTabPane tabId="1" role="tabpanel">
            <Table eventos={eventos}/>
          </MDBTabPane>
          <MDBTabPane tabId="2" role="tabpanel">
            <p className="mt-2">
              Quisquam aperiam, pariatur. Tempora, placeat ratione porro
              voluptate odit minima. Lorem ipsum dolor sit amet,
              consectetur adipisicing elit. Nihil odit magnam minima,
              soluta doloribus reiciendis molestiae placeat unde eos
              molestias.
            </p>
            <p>
              Quisquam aperiam, pariatur. Tempora, placeat ratione porro
              voluptate odit minima. Lorem ipsum dolor sit amet,
              consectetur adipisicing elit. Nihil odit magnam minima,
              soluta doloribus reiciendis molestiae placeat unde eos
              molestias.
            </p>
          </MDBTabPane>
          <MDBTabPane tabId="3" role="tabpanel">
            <p className="mt-2">
              Quisquam aperiam, pariatur. Tempora, placeat ratione porro
              voluptate odit minima. Lorem ipsum dolor sit amet,
              consectetur adipisicing elit. Nihil odit magnam minima,
              soluta doloribus reiciendis molestiae placeat unde eos
              molestias.
            </p>
          </MDBTabPane>
        </MDBTabContent>
      </MDBContainer>
    );
  }
}
export default TabSchedule;