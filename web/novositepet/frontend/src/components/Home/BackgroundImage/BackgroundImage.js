import React from "react";
import "./BackgroundImage.css";
import { MDBMask,MDBContainer,MDBRow} from "mdbreact";
const BackgroundImage = () => { 
  return(
    <MDBContainer fluid className="text-center text-md-left bg">
      <MDBMask pattern={7} className="mask" >
        <MDBContainer fluid className="text-center text-md-left">
          <MDBRow><h1 className="h1-responsive  text-center my-5v">PET Engenharia de Computação</h1></MDBRow>
          <MDBRow><h5 className="h5-responsive  text-center my-5v">Programa de Educação Tutorial do curso de</h5></MDBRow>
          <MDBRow><h5 className="h5-responsive  text-center my-5v">Engenharia de Computação Ufes</h5></MDBRow>
        </MDBContainer>
      </MDBMask>
    </MDBContainer>      
  ); 
};

export default BackgroundImage;

