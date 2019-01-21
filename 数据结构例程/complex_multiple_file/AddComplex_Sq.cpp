#include<stdio.h>
#include"Complex_Sq.h"
Status AddComplex(Complex &Z1,Complex Z2){
    Z1[0]+=Z2[0];
    Z1[1]+=Z2[1];
    return OK;
}