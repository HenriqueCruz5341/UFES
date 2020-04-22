import styled from "styled-components";
import image from "../../../../assets/img/blobs.png";

export const BgImage = styled.div`
  background-image: url(${image});
  height: 100vh;
  background-position: 15%;
  background-repeat: no-repeat;
  background-size: cover;
`;

export const Table = styled.div`
  height: 100%;
  width: 100%;
  display: table;
`;

export const TableCell = styled.div`
  color: white;
  display: table-cell;
  vertical-align: middle;
  text-align: left;
`;

export const Grid = styled.div`
  display: flex;
  flex-direction: column;

  @media (max-width: 576px) {
    align-items: center;
  }

  @media (min-width: 577px) {
    padding-left: 5%;
  }
`;

export const Text = styled.div`
  font-size: ${(props) => props.size + "px"};

  @media (max-width: 576px) {
    width: 80%;
  }
  @media (min-width: 577px) {
    padding-left: 24%;
  }
`;

export const Img = styled.img`
  @media (max-width: 576px) {
    width: 80%;
    padding-bottom: 20px;
  }

  @media (min-width: 577px) {
    width: 50%;
  }
`;
