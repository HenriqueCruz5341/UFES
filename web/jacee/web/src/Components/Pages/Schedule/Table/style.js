import styled from "styled-components";

export const Th = styled.th`
  text-align: center;
`;

export const Td = styled.td`
  &&& {
    text-align: center;
    vertical-align: middle;
    padding: 5px;
    width: ${props => (props.data_col === "hour0" ? "50px" : "auto")};
  }
`;
