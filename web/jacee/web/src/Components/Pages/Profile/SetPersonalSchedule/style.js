import styled from "styled-components";
import { MDBListGroupItem, MDBBadge } from "mdbreact";

export const MDBListGroupItemS = styled(MDBListGroupItem)`
  color: ${props => (props.data_active === "false" ? "#2e2e2e" : "#eee")};
  cursor: pointer;
  background-color: ${props =>
    props.data_active === "true" ? "#2e2e2e" : "#eee"};
  &:hover {
    background: ${props =>
      props.data_active === "true" ? "rgba(46, 46, 46, 0.8)" : "#ddd"};
    color: ${props => (props.data_active === "false" ? "#2e2e2e" : "#eee")};
  }
`;

export const MDBBadgeS = styled(MDBBadge)`
  background-color: ${props =>
    props.data_disabled === 0 ? "#e54d40" : "#0078ae"};
`;
