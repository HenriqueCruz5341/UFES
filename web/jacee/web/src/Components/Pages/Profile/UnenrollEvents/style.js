import styled from "styled-components";
import { MDBListGroupItem, MDBIcon } from "mdbreact";

export const MDBListGroupItemS = styled(MDBListGroupItem)`
  color: #2e2e2e;
  background-color: #eee;
  margin-bottom: auto;
`;

export const MDBIconS = styled(MDBIcon)`
  &&& {
    color: #e54d40;
    cursor: pointer;
  }
  &&&:hover {
    color: #e43020;
  }
`;
