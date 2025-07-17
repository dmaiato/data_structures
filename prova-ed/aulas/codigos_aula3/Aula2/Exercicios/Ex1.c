#include <stdio.h>
#include <stdlib.h>

int main(){
    int a , b, s;
    int *ps;

    printf("\n digite o valor de A e B:");
    scanf("%d %d",&a,&b);

    ps = &s;
    *ps = a + b;

    printf("\n Valor de S = %d\n",s);
    printf("\n Endereço armazenado por ps = %p",ps);
    printf("\n Endereço de ps = %p e o conteudo referenciado %d",&ps,*ps);
    printf("\n Endereço de a = %p e o endereco b = %p\n",&a,&b);
    







}

