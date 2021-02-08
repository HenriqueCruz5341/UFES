#include<stdio.h>


void calc_circulo(float r, float *p_circunferencia, float *p_area){
    float pi = 3.14159265f;
    *p_area = pi * r * r;
    *p_circunferencia = 2 * pi * r;
}
