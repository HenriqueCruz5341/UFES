import styled from "styled-components";
import { MDBIcon, MDBRow, MDBFooter, MDBCol } from "mdbreact";

export const MDBIconS = styled(MDBIcon)`
  padding: 5px;
`;

export const MDBRowS = styled(MDBRow)`
  padding: ${(props) => props.padding} !important;
  text-align: ${(props) => props.textalign} !important;
  justify-content: ${(props) => props.justcontent} !important;
`;

export const MDBColS = styled(MDBCol)`
  @media (max-width: 767px) {
    padding-top: 30px;
  }
`;

export const MDBFooterS = styled(MDBFooter)`
  box-shadow: 0px 0px 20px 0px rgba(51, 50, 51, 0.64);
`;
