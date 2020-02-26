import React from "react";
import { MDBCol, MDBContainer, MDBRow, MDBFooter } from "mdbreact";
import "./footer.css";
import logoJacee from "../../assets/img/logo_footer.png";
import petEngComp from "../../assets/img/petengcomp.png";
import petEngElet from "../../assets/img/logo_pet_eletrica.png";
import ufes from "../../assets/img/ufes.png";
import lar from "../../assets/img/LAR.png";
import crea from "../../assets/img/crea.png";

const FooterPagePro = () => {
  return (
          <MDBFooter color="elegant-color" className="font-small mt-4">
            <MDBContainer fluid className="text-center text-md-left">
              <MDBRow>
                <MDBCol md="5">
                  <img src={logoJacee} alt="Logo JACEE"/>
                </MDBCol>
                <MDBCol md="4">
                  <h5 className="title">REALIZAÇÃO</h5>
                  <MDBRow >
                    <MDBCol xs="4">
                      <img src={petEngComp} alt="Logo JACEE"/>
                    </MDBCol>
                    <MDBCol xs="4">
                      <img src={petEngElet} alt="Logo JACEE"/>
                    </MDBCol>
                    <MDBCol xs="4">
                      <img src={ufes} alt="Logo JACEE"/>
                    </MDBCol>
                  </MDBRow>
                </MDBCol>
                <MDBCol md="3">
                  <h5 className="title">APOIO</h5>
                  <MDBRow>
                    <MDBCol xs="6">
                      <img src={lar} alt="Logo JACEE"/>
                    </MDBCol>
                    <MDBCol xs="6">
                      <img src={crea} alt="Logo JACEE" width="100px"/> 
                    </MDBCol>                    
                  </MDBRow>
                </MDBCol>
              </MDBRow>
            </MDBContainer>
          </MDBFooter>
  );
}

export default FooterPagePro;