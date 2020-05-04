import styled from "styled-components";
import { FiXCircle } from "react-icons/fi";

export const Noticia = styled.div`
  display: flex;
  flex-direction: row;
  border: 2px solid black;
  border-radius: 10px;
  margin-top: 20px;
  padding: 0px 10px;
  width: fit-content;
`;

export const FiXCircleS = styled(FiXCircle)`
  cursor: pointer;
  color: #ff1414;
  position: absolute;
  right: 0px;
  top: 16px;

  &:hover {
    color: #c30e0e;
  }
`;
