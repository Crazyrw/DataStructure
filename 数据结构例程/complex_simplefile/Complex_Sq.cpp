#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
//����״̬�붨��
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE -1
#define OVERFLOW   -2
typedef int  Status;

//�����ṹ��̬�ڴ�˳��洢�ṹ��ʾ
typedef  double  ElemType;
typedef  ElemType*  Complex;

//����������ʵ��
Status InitComplex(Complex &Z,ElemType v1,ElemType v2){
    Z=(ElemType *)malloc(2*sizeof(ElemType));
    if(!Z)exit(OVERFLOW);
    Z[0]=v1;
    Z[1]=v2;
    return OK;
}
Status Add(Complex &Z1,Complex Z2){
    Z1[0]+=Z2[0];
    Z1[1]+=Z2[1];
    return OK;
}
Status PrintComplex(Complex Z){
    printf("%.2f+%-.2f*i\n",Z[0],Z[1]);
    return OK;
}
void main(){
    Complex Z1,Z2;
    InitComplex(Z1,1,1);
    PrintComplex(Z1);
    InitComplex(Z2,2,2);
    PrintComplex(Z2);
    Add(Z1,Z2);
    PrintComplex(Z1);
    PrintComplex(Z2);  
}
