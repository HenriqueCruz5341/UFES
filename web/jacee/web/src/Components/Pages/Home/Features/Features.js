import React from "react";
import { Img, Text, Content, Grid } from "./style";

const FeaturesPage = () => {
  return (
    <div style={{ width: "100%" }}>
      <Img imgId={0}>
        <Content>
          <Grid>
            <Text
              size={50}
              align="right"
              weight="bold"
              type={"title"}
              imgId={0}
            >
              Palestras
            </Text>
            <Text size={20} align="right" weight="300" imgId={0}>
              Lorem ipsum dolor sit amet, consectetur adipisicing elit.
              Reprehenderit maiores aperiam minima assumenda deleni hic.
            </Text>
          </Grid>
        </Content>
      </Img>
      <Img imgId={1}>
        <Content>
          <Grid>
            <Text size={50} align="left" weight="bold" type={"title"} imgId={1}>
              Aulas Teóricas
            </Text>
            <Text size={20} align="left" weight="300" imgId={1}>
              Lorem ipsum dolor sit amet, consectetur adipisicing elit.
              Reprehenderit maiores aperiam minima assumenda deleni hic.
            </Text>
          </Grid>
        </Content>
      </Img>
      <Img imgId={2}>
        <Content>
          <Grid>
            <Text
              size={50}
              align="right"
              weight="bold"
              type={"title"}
              imgId={2}
            >
              Minicursos
            </Text>
            <Text size={20} align="right" weight="300" imgId={2}>
              Lorem ipsum dolor sit amet, consectetur adipisicing elit.
              Reprehenderit maiores aperiam minima assumenda deleni hic.
            </Text>
          </Grid>
        </Content>
      </Img>
    </div>
  );
};

export default FeaturesPage;
