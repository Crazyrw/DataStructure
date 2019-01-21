#include<stdio.h>
#include"Complex_Sq.h"
void main(){
    Complex Z1,Z2;
    InitComplex(Z1,1,1);
    PrintComplex(Z1);
    InitComplex(Z2,2,2);
    PrintComplex(Z2);
    AddComplex(Z1,Z2);
    PrintComplex(Z1);
    PrintComplex(Z2);  
}