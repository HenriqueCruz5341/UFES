import React from "react";
import { MDBCarousel, MDBCarouselCaption, MDBCarouselInner, MDBCarouselItem, MDBView } from
"mdbreact";

const CarouselPage = () => {
  return (
      <MDBCarousel
      activeItem={1}
      length={4}
      showControls={true}
      showIndicators={true}
      className="z-depth-1"
    >
      <MDBCarouselInner>
        <MDBCarouselItem itemId="1">
          <MDBView>
            <img
              className="d-block w-100"
              src="https://i.picsum.photos/id/89/1920/720.jpg"
              alt="First slide"
            />
          </MDBView>
          <MDBCarouselCaption>
            <h3 className="h3-responsive">Light mask</h3>
            <p>First text</p>
          </MDBCarouselCaption>
        </MDBCarouselItem>
        <MDBCarouselItem itemId="2">
          <MDBView>
            <img
              className="d-block w-100"
              src="https://i.picsum.photos/id/90/1920/720.jpg"
              alt="Second slide"
            />
          </MDBView>
          <MDBCarouselCaption>
            <h3 className="h3-responsive">Strong mask</h3>
            <p>Second text</p>
          </MDBCarouselCaption>
        </MDBCarouselItem>
        <MDBCarouselItem itemId="3">
          <MDBView>
            <img
              className="d-block w-100"
              src="https://i.picsum.photos/id/91/1920/720.jpg"
              alt="Third slide"
            />
          </MDBView>
          <MDBCarouselCaption>
            <h3 className="h3-responsive">Slight Mast</h3>
            <p>Third text</p>
          </MDBCarouselCaption>
        </MDBCarouselItem>
        <MDBCarouselItem itemId="4">
          <MDBView>
            <img
              className="d-block w-100"
              src="https://i.picsum.photos/id/92/1920/720.jpg"
              alt="Third slide"
            />
          </MDBView>
          <MDBCarouselCaption>
            <h3 className="h3-responsive">Slight Mast</h3>
            <p>Third text</p>
          </MDBCarouselCaption>
        </MDBCarouselItem>
      </MDBCarouselInner>
    </MDBCarousel>
  );
}

export default CarouselPage;