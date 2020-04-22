import styled from "styled-components";

export const Text = styled.div`
  font-size: ${(props) => props.size + "px"};
  font-weight: ${(props) => props.weight};

  @media (max-width: 576px) {
    text-align: left;
    padding: 10px 5%;
  }

  @media (min-width: 577px) {
    text-align: ${(props) => (props.type === "title" ? "center" : "left")};
    padding: 15px 20%;
  }
`;

export const Content = styled.div`
  width: 100%;
  padding-top: 100px;

  @media (min-width: 577px) {
    text-align: center;
  }
`;

export const ContentApp = styled.div`
  @media (max-width: 710px) {
    display: flex;
    flex-direction: column;
    padding: 100px 0px;
    align-items: center;
  }

  @media (min-width: 711px) {
    display: flex;
    justify-content: center;
    padding: 100px 20%;
  }
`;

export const TextApp = styled.div`
  font-size: ${(props) => props.size + "px"};
  font-weight: ${(props) => props.weight};

  @media (max-width: 710px) {
    text-align: center;
  }

  @media (min-width: 711px) {
    padding-right: 10px;
  }
`;
