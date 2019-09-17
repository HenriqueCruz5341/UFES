#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int codigo;
    float preco;
    int qtdEstoque;
}tProduto;

tProduto LeProduto();
int EhProduto1MaiorQ2(tProduto p1, tProduto p2);
int EhProduto1MenorQ2(tProduto p1, tProduto p2);
int TemProdutoEmEstoque(tProduto p);
void ImprimeProduto(tProduto p);

int main(int argc, char** argv) {
    tProduto produto, maProd, meProd;
    int i, num, temProd;
    
    scanf("%d", &num);
    
    for(i = 0; i < num; i++){
        produto = LeProduto();
        
        if(!i){
            maProd = produto;
            meProd = produto;
        }
        
        temProd = TemProdutoEmEstoque(produto);
        
        if(!temProd){
            printf("FALTA:");
            ImprimeProduto(produto);
        }
        
        if(EhProduto1MaiorQ2(produto, maProd)){
            maProd = produto;
        }
        if(EhProduto1MenorQ2(produto, meProd)){
            meProd = produto;
        }
    }
    printf("MAIOR:");
    ImprimeProduto(maProd);
    printf("MENOR:");
    ImprimeProduto(meProd);
    
    return 0;
}

tProduto LeProduto(){
    tProduto p;
    
    scanf("%d;%f;%d", &p.codigo, &p.preco, &p.qtdEstoque);
    
    return p;
}

int EhProduto1MaiorQ2(tProduto p1, tProduto p2){
    if(p1.preco > p2.preco){
        return 1;
    }else{
        return 0;
    }
}

int EhProduto1MenorQ2(tProduto p1, tProduto p2){
    if(p1.preco < p2.preco){
        return 1;
    }else{
        return 0;
    }
}

int TemProdutoEmEstoque(tProduto p){
    if(p.qtdEstoque == 0){
        return 0;
    }else {
        return 1;
    }
}

void ImprimeProduto(tProduto p){
    printf("COD %d, PRE %.2f, QTD %d\n", p.codigo, p.preco, p.qtdEstoque);
}
