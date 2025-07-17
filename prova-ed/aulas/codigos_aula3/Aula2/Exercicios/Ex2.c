#include <stdio.h>
#include <stdlib.h>

int main(){
    int a , b;
    int *ps;

    ps = (int*)malloc(sizeof(int));

    printf("\n digite o valor de A e B:");
    scanf("%d %d",&a,&b);

    *ps = a + b;

    printf("\n Valor de S = %d\n",*ps);
    printf("\n Endereço armazenado por ps = %p",ps);
    printf("\n Endereço de ps = %p e o conteudo referenciado %d",&ps,*ps);
    printf("\n Endereço de a = %p e o endereco b = %p\n",&a,&b);

    free(ps); //liberando memoria 

    printf("\n Valor de S = %d\n",*ps);
    printf("\n Endereço armazenado por ps = %p",ps);
    printf("\n Endereço de ps = %p e o conteudo referenciado %d",&ps,*ps);
    printf("\n Endereço de a = %p e o endereco b = %p\n",&a,&b);








}

