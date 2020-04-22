import styled from "styled-components";
import { MDBNav, MDBContainer } from "mdbreact";

export const MDBNavS = styled(MDBNav)`
  box-shadow: 2px 2px 5px 0px rgba(0, 0, 0, 0.51);

  @media (max-width: 766px) {
    margin-bottom: 70px;
  }
`;

export const MDBContainerS = styled(MDBContainer)`
  padding-top: 100px;

  @media (min-width: 767px) {
    padding-top: 200px;
  }
`;
