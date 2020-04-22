import styled from "styled-components";
import palestras from "../../../../assets/img/palestrasS.JPG";
import aulasTeoricasS from "../../../../assets/img/aulasTeoricasS.JPG";
import minicursos from "../../../../assets/img/minicursosS.jpg";

const colorsL = [
  "90deg, rgba(0, 0, 0, 0) 10%, rgba(226, 58, 105, 1) 40%, rgba(226, 58, 105, 1) 100%",
  "-90deg, rgba(0, 0, 0, 0) 10%, rgba(19, 156, 217, 1) 40%, rgba(19, 156, 217, 1) 100%",
  "90deg, rgba(0, 0, 0, 0) 10%, rgba(247, 180, 5, 1) 40%, rgba(247, 180, 5, 1) 100%",
];
const colorsS = [
  "90deg, rgba(0, 0, 0, 0) 10%, rgba(226, 58, 105, 1) 40%, rgba(226, 58, 105, 1) 100%",
  "-90deg, rgba(0, 0, 0, 0) 10%, rgba(19, 156, 217, 1) 40%, rgba(19, 156, 217, 1) 100%",
  "90deg, rgba(0, 0, 0, 0) 10%, rgba(247, 180, 5, 1) 40%, rgba(247, 180, 5, 1) 100%",
];
const imgs = [palestras, aulasTeoricasS, minicursos];

export const Img = styled.div`
  margin-top: 100px;
  height: 300px;
  background-repeat: no-repeat;

  @media (max-width: 900px) {
    ${(props) => (props.imgId % 2 ? "background-position: right;" : "")}
    width: 100%;
    background-image: linear-gradient(${(props) => colorsS[props.imgId]}),
      url(${(props) => imgs[props.imgId]});
  }

  @media (min-width: 901px) {
    ${(props) =>
      props.imgId % 2
        ? "margin-right: 40%; background-position: right;"
        : "margin-left: 40%;"}
    width: 60%;
    background-image: linear-gradient(${(props) => colorsL[props.imgId]}),
      url(${(props) => imgs[props.imgId]});
  }
`;

export const Text = styled.div`
  font-size: ${(props) => props.size + "px"};
  text-align: ${(props) => props.align};
  font-weight: ${(props) => props.weight};
  color: white;

  @media (max-width: 900px) {
    padding: ${(props) => {
      if (props.type === "title" && props.imgId % 2) return "0px 0px 30px 5%";
      if (!(props.type === "title") && props.imgId % 2) return "0px 15% 0px 5%";
      if (!(props.type === "title") && !(props.imgId % 2))
        return "0px 5% 0px 15%";
      if (props.type === "title" && !(props.imgId % 2))
        return "0px 5% 30px 0px";
    }};
  }

  @media (min-width: 901px) {
    padding: ${(props) => {
      if (props.type === "title" && props.imgId % 2) return "0px 0px 30px 10%";
      if (!(props.type === "title") && props.imgId % 2)
        return "0px 40% 0px 10%";
      if (!(props.type === "title") && !(props.imgId % 2))
        return "0px 10% 0px 40%";
      if (props.type === "title" && !(props.imgId % 2))
        return "0px 10% 30px 0px";
    }};
  }
`;

export const Content = styled.div`
  width: 100%;
  height: 100%;
  display: table;
`;

export const Grid = styled.div`
  display: table-cell;
  vertical-align: middle;
`;
