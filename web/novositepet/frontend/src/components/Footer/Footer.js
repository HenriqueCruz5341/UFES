import React from "react";
import logoPet from '../../assets/Logo-PET.svg'
import iconeInstagram from '../../assets/icone_instagram.svg'
import iconeFacebook from '../../assets/icone_facebook.svg'
import iconeEmail from '../../assets/icone_email.svg'
import { MDBCol, MDBContainer, MDBRow, MDBFooter,MDBIcon } from "mdbreact";
import "./Footer.css"

const Footer = () => {
  return (
    <MDBFooter color="elegant-color-dark" className="font-small pt-4 mt-4">
      <MDBContainer fluid className="text-center text-md-left">
        <MDBRow>
          <MDBCol md="8"  className="colLogo">
              <MDBContainer>
                  <MDBRow >
                    <MDBCol size="3"><img src={logoPet} alt="Logo PET" className="logoPet"  /></MDBCol>
                    <MDBCol className="colDescription">
                      <MDBRow className= "desc">PET Engenharia de Computação</MDBRow>
                      <MDBRow>CT VII – UFES – Goiabeiras, Vitória – ES, 29075-073. Sala 36, 2º andar</MDBRow>
                    </MDBCol>
                  </MDBRow>
              </MDBContainer>
          </MDBCol>
          <MDBCol  size="3">
            <MDBContainer fluid className="text-center text-md-left er">
                <MDBRow>
                    <MDBCol size="2">
                      <MDBIcon fab icon="instagram" />
                    </MDBCol>
                    <MDBCol  size="4">
                      petengcomp
                    </MDBCol>
                    <MDBCol size="2" >
                      <MDBIcon fab icon="facebook" />
                    </MDBCol>
                    <MDBCol size="3">
                      @PETEngCompUfes
                    </MDBCol>
                </MDBRow>
                <MDBRow >
                  <MDBCol size="2" >
                    <MDBIcon icon="envelope" />
                  </MDBCol>
                  <MDBCol>
                    petengcomp@inf.ufes.br
                  </MDBCol>
                </MDBRow>
            </MDBContainer>
          </MDBCol>
        </MDBRow>
      </MDBContainer>
      <div className="footer-copyright text-center py-3">
        <MDBContainer fluid>
          &copy; {new Date().getFullYear()} Copyright: PET Engenharia de Computação - Ufes
        </MDBContainer>
      </div>
    </MDBFooter>
  );
}

export default Footer;