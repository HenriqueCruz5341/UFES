import styled from "styled-components";
import { MDBBtn } from "mdbreact";

export const MDBBtnS = styled(MDBBtn)`
  background-color: ${(props) => props.btncolor} !important;
  transition: background-color 0.15s ease-in-out !important;

  &&&:active {
    background-color: ${(props) => {
      const color = props.btncolor.slice(4, props.btncolor.length - 1);
      let rgb = color.split(",").map((c) => Number.parseInt(c));
      rgb = rgb.map((elem) => Number.parseInt(elem - elem * 0.4));
      return `rgb(${rgb[0]}, ${rgb[1]}, ${rgb[2]})`;
    }} !important;
  }
`;
