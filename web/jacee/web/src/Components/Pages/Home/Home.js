import React from "react";
import FeaturesPage from "./Features/Features";
import BackgroundImage from "./BackgroundImage/BackgroundImage";
import playStoreButton from "../../../assets/img/playStoreButton.png";
import { Text, Content, ContentApp, TextApp } from "./style";

function Home() {
  return (
    <div className="Home">
      <BackgroundImage />
      <Content>
        <Text size={26} weight={500} type="title">
          Por que participar da <b>JACEE</b>?
        </Text>
        <Text size={16} weight={300} type="body">
          <div>
            O evento acontece em uma data que visa não atrapalhar o semestre dos
            alunos, entre os dias{" "}
            <strong style={{ color: "#e5537c", fontSize: "20px" }}>
              6 e 10 de Julho
            </strong>{" "}
            no{" "}
            <strong style={{ color: "#56b8e3", fontSize: "20px" }}>
              Centro Tecnológico da Ufes, Goiabeiras
            </strong>
            .
          </div>
          <br />
          <div>
            Oportunidade de atualizar seus conhecimentos nas áreas de Computação
            Elétrica e Eletrônica com diversos minicursos, palestras e aulas
            teóricas.
          </div>
        </Text>
      </Content>
      <FeaturesPage />
      <ContentApp>
        <div>
          <TextApp size={24} weight={500}>
            Tem interesse?
          </TextApp>
          <TextApp size={26} weight={700}>
            Baixe o nosso App
          </TextApp>
        </div>
        <div>
          <a
            href="https://play.google.com/store/?utm_source=latam_Med&utm_medium=hasem&utm_content=Feb0217&utm_campaign=Evergreen&pcampaignid=MKT-DR-latam-br-1002290-Med-hasem-py-Evergreen-Feb0217-Text-Institucional&gclid=CjwKCAjwkPX0BRBKEiwA7THxiDR0jhhVbkftnv6dN3MJklgqdThUOXgfWWzyqwc07BbFgkRtKPQH9RoC3lQQAvD_BwE&gclsrc=aw.ds"
            target="_blank"
            rel="noopener noreferrer"
          >
            <img
              src={playStoreButton}
              alt="Link app PlayStore"
              width="215px"
              height="83px"
            />
          </a>
        </div>
      </ContentApp>
    </div>
  );
}

export default Home;
