#include<stdio.h>

void div (int D, int d, int *q, int *r){
    *r = D % d;
    *q = D / d;
}

