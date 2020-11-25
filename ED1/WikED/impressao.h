#ifndef Impressao_H
#define Impressao_H

/* Função responsável apenas por imprimir mensagens de erro no arquivo de log
*inputs: uma string com a mensagem, e um char* caso queira imprimir o valor de uma variável,
    é possivel passar NULL para esse segundo parâmetro também, se não quiser imprimir nenhuma variável.
*outpus: ponteiro para uma nova contribuição inicializada
*pre-condicao: os parâmetros devem estar devidamente preenchidos
*pos-condicao: a mensagem passada juntamente com a variável são impressas no arquivo log.txt
*/
void imprimeLog(char* mensagem, char* var);

#endif
