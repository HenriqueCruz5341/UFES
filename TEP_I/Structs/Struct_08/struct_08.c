/* Estrutura para representar um ponto no espaço 2D */
typedef struct vetor {
   float x;
   float y;
   float z;
} Vetor;

/* INSIRA SEU CODIGO AQUI, CASO DESEJE CRIAR ALGUMA FUNCAO AUXILIAR */



/* Funcao que indica se um dado ponto p estah localizado dentro ou fora de um retangulo.
   O retangulo eh definido por seus vertices inferior esquerdo v1 e superior direito v2.
   A funcao retorna 1 caso o ponto esteja localizado dentro do retangulo, e 0 caso contrario,
   sendo que os limites sao considerados como parte do retangulo */
float dot (Vetor v1, Vetor v2) {
    float prod;
    
    prod = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
    
    return prod;
}

