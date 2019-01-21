#include<stdio.h>
#include"Complex_Sq.h"
Status PrintComplex(Complex Z){
    printf("%.2f+%-.2f*i\n",Z[0],Z[1]);
    return OK;
}