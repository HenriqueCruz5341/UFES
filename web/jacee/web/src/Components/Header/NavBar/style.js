import styled from "styled-components";
import { MDBNavLink, MDBDropdownToggle, MDBDropdownItem } from "mdbreact";

export const MDBNavLinkLogo = styled(MDBNavLink)`
  &&& {
    padding: 0;
    padding-left: 8px;
  }
`;

export const MDBNavLinkS = styled(MDBNavLink)`
  &&&&& {
    color: #555;
    font-size: 15px;
    &:hover {
      color: black;
    }
  }
`;

export const MDBDropdownToggleS = styled(MDBDropdownToggle)`
  &&&&& {
    color: #555;
    font-size: 15px;
    &:hover {
      color: black;
    }
  }
`;

export const MDBDropdownItemS = styled(MDBDropdownItem)`
  &&&&& {
    color: #555;
    font-size: 15px;
    font-weight: 300;
    &:hover {
      color: black;
      background-color: #fff;
    }
  }
`;
