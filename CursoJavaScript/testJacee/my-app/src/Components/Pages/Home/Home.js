import React from 'react';
import { MDBContainer, MDBRow, MDBCol, MDBIcon, MDBAnimation } from "mdbreact";
import CarouselPage from '../../Main/Carousel/Carousel';
import './home.css';
import FeaturesPage from '../../Main/Features/Features';
//import BackgroundImage from '../../BackgroundImage/BackgroundImage';


function Home() {
  return (
    <div className="Home" style={{paddingTop: "100px"}}>
      <CarouselPage/>
      <MDBContainer>
      <MDBRow>
      <MDBCol className="date" md="6">
        <MDBAnimation reveal type="fadeInLeft">
          <MDBIcon icon="calendar-alt" className="icon"/><h5>06 A 10 DE JULHO</h5>
        </MDBAnimation>
        </MDBCol>
        <MDBCol className="local" md="6">
        <MDBAnimation reveal type="fadeInRight">
          <MDBIcon icon="map-marked-alt" className="icon"/><h5>CENTRO TECNOLÓGICO, UFES</h5> VITÓRIA - ES
        </MDBAnimation>
        </MDBCol>
      </MDBRow>
    </MDBContainer>
    <FeaturesPage/>
    </div>
  );
}

export default Home;
