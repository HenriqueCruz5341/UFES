import React from "react";
import { MDBCol, MDBContainer } from "mdbreact";
import { MDBIconS, MDBRowS, MDBFooterS, MDBColS } from "./style";
import logoJacee from "../../assets/img/logo_jacee_branca.svg";
import petEngComp from "../../assets/img/petengcomp.png";
import petEngElet from "../../assets/img/logo_pet_eletrica.png";
import ufes from "../../assets/img/ufes.png";
import lar from "../../assets/img/LAR.png";
import crea from "../../assets/img/crea.png";
import playStoreButton from "../../assets/img/playStoreButton.png";

const FooterPagePro = () => {
  return (
    <MDBFooterS color="elegant-color" className="font-small mt-4">
      <MDBContainer fluid className="text-center text-md-left">
        <MDBRowS padding="30px 0 0 0" textalign="center">
          <MDBColS md="3">
            <img src={logoJacee} height="40%" alt="Logo JACEE" />
            <MDBRowS padding="7px 0 0 26%" textalign="center">
              <a
                href="https://www.instagram.com/?hl=pt-br"
                target="_blank"
                rel="noopener noreferrer"
              >
                <MDBIconS fab icon="instagram" />
                jacee
              </a>
            </MDBRowS>
            <MDBRowS padding="0px 0 0 26%" textalign="center">
              <MDBIconS far icon="envelope" />
              jacee.ufes@gmail.com
            </MDBRowS>
          </MDBColS>
          <MDBColS md="3">
            <h5 className="title">REALIZAÇÃO</h5>
            <MDBRowS padding="7px 0 0 0" justcontent="center">
              <MDBCol xs="4" style={{ padding: "0px 5px" }}>
                <a
                  href="https://pet.inf.ufes.br/"
                  target="_blank"
                  rel="noopener noreferrer"
                >
                  <img src={petEngComp} alt="Logo PETEngCom" />
                </a>
              </MDBCol>
              <MDBCol xs="4" style={{ padding: "0px 5px" }}>
                <a
                  href="https://www.peteletricaufes.com/"
                  target="_blank"
                  rel="noopener noreferrer"
                >
                  <img src={petEngElet} alt="Logo PETElétrica" />
                </a>
              </MDBCol>
              <MDBCol xs="4" style={{ padding: "0px 5px" }}>
                <a
                  href="http://www.ufes.br/"
                  target="_blank"
                  rel="noopener noreferrer"
                >
                  <img src={ufes} alt="Logo UFES" />
                </a>
              </MDBCol>
            </MDBRowS>
          </MDBColS>
          <MDBColS md="3">
            <h5 className="title">APOIO</h5>
            <MDBRowS padding="7px 0 0 0" justcontent="center">
              <MDBCol xs="6" style={{ padding: "0px 5px" }}>
                <a
                  href="http://lar.inf.ufes.br/"
                  target="_blank"
                  rel="noopener noreferrer"
                >
                  <img src={lar} alt="Logo LAR" />
                </a>
              </MDBCol>
              <MDBCol xs="6" style={{ padding: "0px 5px" }}>
                <a
                  href="http://www.creaes.org.br/"
                  target="_blank"
                  rel="noopener noreferrer"
                >
                  <img src={crea} alt="Logo CREA" width="100px" />
                </a>
              </MDBCol>
            </MDBRowS>
          </MDBColS>
          <MDBColS md="3">
            <h5 className="title">BAIXE NOSSO APP</h5>
            <MDBRowS padding="7px 0 0 0" justcontent="center">
              <a
                href="https://play.google.com/store/?utm_source=latam_Med&utm_medium=hasem&utm_content=Feb0217&utm_campaign=Evergreen&pcampaignid=MKT-DR-latam-br-1002290-Med-hasem-py-Evergreen-Feb0217-Text-Institucional&gclid=CjwKCAjwkPX0BRBKEiwA7THxiDR0jhhVbkftnv6dN3MJklgqdThUOXgfWWzyqwc07BbFgkRtKPQH9RoC3lQQAvD_BwE&gclsrc=aw.ds"
                target="_blank"
                rel="noopener noreferrer"
              >
                <img
                  src={playStoreButton}
                  alt="Link app PlayStore"
                  width="129px"
                  height="50px"
                />
              </a>
            </MDBRowS>
          </MDBColS>
        </MDBRowS>
      </MDBContainer>
      <div className="footer-copyright text-center py-3">
        <MDBContainer fluid>
          2020 © Desenvolvido por PET Engenharia de Computação. Todos os
          direitos reservados
        </MDBContainer>
      </div>
    </MDBFooterS>
  );
};

export default FooterPagePro;
