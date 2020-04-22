import styled from "styled-components";
import { MDBTableBody, MDBTableHead } from "mdbreact";

export const MDBTableBodyS = styled(MDBTableBody)`
  &&& {
  }
`;

export const MDBTableHeadS = styled(MDBTableHead)`
  background-color: ${(props) =>
    props.data_disabled === 0 ? "#e54d40" : "#0078ae"};
`;
