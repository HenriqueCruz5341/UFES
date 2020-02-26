import React from "react";
import {  MDBRow, MDBCol, MDBIcon, MDBAnimation } from "mdbreact";

const FeaturesPage = () => {
  return (
      <section className="text-center my-5 container">
        <h2 className="h1-responsive font-weight-bold my-5">
          Por que participar da JACEE?
        </h2>
        <p className="lead grey-text w-responsive mx-auto mb-5">
          Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do
          eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim
          ad minim veniam.
        </p>
        <MDBRow>
          <MDBCol md="4">
            <MDBAnimation reveal type="fadeInUp">
            <MDBIcon icon="user" size="5x" className="red-text"/>
              <h5 className="font-weight-bold my-4 black-text">Palestras</h5>
              <p className="grey-text mb-md-0 mb-5">
                Lorem ipsum dolor sit amet, consectetur adipisicing elit.
                Reprehenderit maiores aperiam minima assumenda deleniti hic.
              </p>
              </MDBAnimation>
          </MDBCol>
          <MDBCol md="4">
            <MDBAnimation reveal type="fadeInUp" delay="0.5s">
              <MDBIcon icon="comments" size="5x" className="blue-text" />
              <h5 className="font-weight-bold my-4 black-text">Mesas redondas</h5>
              <p className="grey-text mb-md-0 mb-5">
                Lorem ipsum dolor sit amet, consectetur adipisicing elit.
                Reprehenderit maiores aperiam minima assumenda deleniti hic.
              </p>
            </MDBAnimation>
          </MDBCol>
          <MDBCol md="4">
            <MDBAnimation reveal type="fadeInUp" delay="1s">
              <MDBIcon far icon="keyboard" size="5x" className="yellow-text" />
              <h5 className="font-weight-bold my-4 black-text">Minicursos</h5>
              <p className="grey-text mb-md-0 mb-5">
                Lorem ipsum dolor sit amet, consectetur adipisicing elit.
                Reprehenderit maiores aperiam minima assumenda deleniti hic.
              </p>
            </MDBAnimation>
          </MDBCol>
        </MDBRow>
      </section>
  );
}

export default FeaturesPage;