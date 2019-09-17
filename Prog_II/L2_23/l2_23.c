 
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.c
 * Author: 2019107869
 *
 * Created on 10 de Abril de 2019, 10:13
 */

#include <stdio.h>
#include <stdlib.h>

/*
 *
 */
int main(int argc, char** argv) {
    char c;
    int contAb = 0, primeiro = 0, contFe = 0, i = 0;

    while (1) {
        scanf("%c", &c);
        if (i == 0) {
            printf("RESP:");
        }
        i++;
        
        if (c == '.' && primeiro == 0) {
            break;
        }

        if (c == '(' && primeiro == 0) {
            primeiro++;
            contAb++;
        } else if (primeiro > 0) {
            if (c == '(') {
                contAb++;
            }
            if (c == ')') {
                contFe++;
            }
            if (contAb != contFe) {
                printf("%c", c);
            } else if (contAb == contFe) {
                primeiro = 0;
                contAb = 0;
                contFe = 0;
            }
        }
    }

    return 0;
}
