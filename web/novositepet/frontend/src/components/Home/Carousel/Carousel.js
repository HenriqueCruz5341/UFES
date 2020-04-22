import React from "react";
import selecao from "../../../assets/Selecao.png"
import { MDBCarousel, MDBCarouselInner, MDBCarouselItem, MDBView, MDBContainer ,MDBCol,MDBRow} from
"mdbreact";
import "./Carousel.css"

const Carousel = () => {
  return (
    <div className="news">
      <div className="title"><h2>Notícias</h2></div>
      <div className="carousel">
        <MDBContainer >
            <MDBCarousel
              activeItem={1}
              length={1}
              showControls={true}
              showIndicators={true}
              className="z-depth-1 image"
  
            >
              <MDBCarouselInner >
                <MDBCarouselItem itemId="1" >
                  <MDBView>
                    <img
                      className="d-block w-100"
                      src={selecao}
                      alt="First slide"
                    />
                  </MDBView>
                </MDBCarouselItem>
                {/* <MDBCarouselItem itemId="2">
                  <MDBView>
                    <img
                      className="d-block w-100"
                      src="https://mdbootstrap.com/img/Photos/Slides/img%20(129).jpg"
                      alt="Second slide"
                    />
                  </MDBView>
                </MDBCarouselItem>
                <MDBCarouselItem itemId="3">
                  <MDBView>
                    <img
                      className="d-block w-100"
                      src="https://mdbootstrap.com/img/Photos/Slides/img%20(70).jpg"
                      alt="Third slide"
                    />
                  </MDBView>
                </MDBCarouselItem> */}
              </MDBCarouselInner>
            </MDBCarousel>
        </MDBContainer>
      </div>
      <MDBContainer className="description">
        <MDBRow><h5 className="title">Processo Seletivo 2020/1</h5></MDBRow>
        <MDBRow className="line">Está aberto o edital para o processo
          seletivo de 2020/1.
        </MDBRow>
        <MDBRow className="line">
          As inscrições vão até o dia 1 de abril.
          Cheque o regulamento e participe da
          seleção!
        </MDBRow>
      </MDBContainer>

      
    </div>
  );
}

export default Carousel;