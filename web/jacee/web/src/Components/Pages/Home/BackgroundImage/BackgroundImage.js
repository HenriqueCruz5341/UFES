import React from "react";
import { BgImage, Table, TableCell, Grid, Text, Img } from "./style";
import logoJacee from "../../../../assets/img/logo_jacee_branca.svg";

const BackgroundImage = () => {
  return (
    <BgImage>
      <Table>
        <TableCell>
          <Grid>
            <Img src={logoJacee} alt="Logo JACEE" />
            <Text size={24} weigth={400}>
              Jornada de Atualização em{" "}
              <strong>
                Computação,
                <br /> Elétrica e Eletrônica
              </strong>
            </Text>
            <Text size={20} weigth={200}>
              Faça sua <strong>inscrição</strong> e participe!
            </Text>
          </Grid>
        </TableCell>
      </Table>
    </BgImage>
  );
};

export default BackgroundImage;
