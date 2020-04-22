import styled from "styled-components";
import { MDBRow, MDBCol, MDBIcon } from "mdbreact";
import InputMask from "react-input-mask";

export const MDBRowS = styled(MDBRow)`
  padding-bottom: 20px !important;
`;

export const InputEdit = styled.div`
  display: flex;
`;

export const MDBIconS = styled(MDBIcon)`
  border: 1px solid #ced4da;
  background-color: #e9ecef;
  padding: 10px 3px 9px 5px;
  border-top-right-radius: 0.25rem;
  border-bottom-right-radius: 0.25rem;
  font-size: 15px;
`;

export const InputMaskS = styled(InputMask)`
  border-top-right-radius: 0px;
  border-bottom-right-radius: 0px;
  border-top-left-radius: 0.25rem;
  border-bottom-left-radius: 0.25rem;
`;

export const MDBColS = styled(MDBCol)`
  @media (max-width: 575px) {
    padding-bottom: 20px;
  }
`;
