import React from "react";
import { MDBRow, MDBCol, MDBCard, MDBCardBody, MDBIcon, MDBBtn, MDBInput } from "mdbreact";
import "./Contact.css"

const ContactPage = () => {
  return (
    <section className="my-5">
      <h2 className="h1-responsive title marginTop font-weight-bold text-center my-5v">
        Entre com Contato!
      </h2>
      <MDBRow className="marginTitle">
        <MDBCol lg="5" className="lg-0 mb-4">
          <MDBCard>
            <MDBCardBody>
              <div className="form-header title accent-1">
                <h3 className="mt-2">
                  <MDBIcon icon="envelope" /> Mande uma Mensagem:
                </h3>
              </div>
              <form  >
                    <input type="text" className="form-control" placeholder="Nome " />
                    <br />
                
                    <input type="email"  className="form-control" placeholder="Email " />
                    <br />
                
                    <input type="text"  className="form-control" placeholder="Assunto " />
                    <br />
                    
                    <textarea type="text"  className="form-control" rows="3" placeholder="Mensagem "/>
                    <div className="text-center mt-4">
                    <MDBBtn  outline  type="submit">
                        Enviar
                    </MDBBtn>
                    </div>
                </form> 
            </MDBCardBody>
          </MDBCard>
        </MDBCol>
        <MDBCol lg="7">
          <div
            id="map-container"
            className="rounded z-depth-1-half map-container"
            style={{ height: "443px" }}
          >
            <iframe
              src="https://www.google.com/maps/embed?pb=!1m14!1m8!1m3!1d14970.596826259594!2d-40.305981!3d-20.2733782!3m2!1i1024!2i768!4f13.1!3m3!1m2!1s0x0%3A0x7c50a8cb2f88472c!2sPET%20Engenharia%20da%20Computa%C3%A7%C3%A3o%20UFES!5e0!3m2!1spt-BR!2sbr!4v1587417017850!5m2!1spt-BR!2sbr"
              title="This is a unique title"
              width="100%"
              height="100%"
              frameBorder="0"
              style={{ border: 0 }}
            />
          </div>
          <br />
          <MDBRow className="text-center">
            <MDBCol md="4">
              <MDBBtn tag="a" floating  className="accent-1">
                <MDBIcon icon="map-marker-alt" />
              </MDBBtn>
              <p>Universidade Federal do Espírito Santo.</p>
              <p className="mb-md-0">Departamento de Informática, CT-7, 2º andar, sala 36.</p>
            </MDBCol>
            <MDBCol md="4">
              <MDBBtn tag="a" floating  className="accent-1">
                <MDBIcon icon="phone" />
              </MDBBtn>
              <p>(27)3335-2139</p>
              <p className="mb-md-0">(27)4009-2139</p>
            </MDBCol>
            <MDBCol md="4">
              <MDBBtn tag="a" floating  className="accent-1">
                <MDBIcon icon="envelope" />
              </MDBBtn>
              <p>info@gmail.com</p>
              <p className="mb-md-0">petengcomp@inf.ufes.br</p>
            </MDBCol>
          </MDBRow>
        </MDBCol>
      </MDBRow>
    </section>
  );
}

export default ContactPage;