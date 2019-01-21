#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include"Complex_Sq.h"
Status InitComplex(Complex &Z,ElemType v1,ElemType v2){
    Z=(ElemType *)malloc(2*sizeof(ElemType));
    if(!Z)exit(OVERFLOW);
    Z[0]=v1;
    Z[1]=v2;
    return OK;
}