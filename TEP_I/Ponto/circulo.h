/* circulo.h

	TAD Circulo: tipo abstrato de dado para representar um circulo no RxR.
	
	@author Rodrigo Laiola Guimaraes <rlaiola@inf.ufes.br>

*/

/************************************
 NAO MODIFIQUE NADA NESTE ARQUIVO.
*************************************/

#ifndef _CIRCULO
#define _CIRCULO
#include"ponto.h"

/********************************************************************
	TAD: Circulo (centro, raio)
	
	OBS: Nao modifique nada neste arquivo.
********************************************************************/

typedef struct circulo Circulo;

/* Funcoes exportadas */

/* Funcao cria 
** Retorna um circulo com centro nas coordenadas (x,y) e raio r
*/
Circulo* circulo_cria (float x, float y, float r);

void circulo_libera(Circulo *c);

/* Funcao acessa centro
** Retorna o ponto que representa o centro do circulo
*/
Ponto* circulo_acessa_centro (Circulo* c);

/* Funcao acessa raio
** Retorna o valor do raio do circulo
*/
float circulo_acessa_raio (Circulo* c);

/* Funcao atribui centro
** Atribui novo valor para o centro de um circulo e retorna o circulo modificado
*/
Circulo* circulo_atribui_centro (Circulo* c, Ponto* p);

/* Funcao atribui raio
** Atribui novo valor para o raio de um circulo e retorna o circulo modificado
*/
Circulo* circulo_atribui_raio (Circulo* c, float r);

/* Funcao interior
** Retorna 1 se o ponto estiver dentro do circulo e 0, caso contrario
*/
int circulo_interior (Circulo* c, Ponto* p);

#endif /* _CIRCULO */