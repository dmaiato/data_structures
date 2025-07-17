#include <stdio.h>
#include <stdlib.h>

void somaValores(int a, int b, int *pc){
    *pc = a +b;
}

void dividaValores(int *pa, int *pb, double *pc){
    *pc = *pa/(double)(*pb);
}

int main(){

    int x, y, s=0; //variavel
    double d;
    printf("\n Informe dois Valores:");
    scanf("%d%d",&x,&y);

    somaValores(x,y,&s);
    printf("\n A soma de %d + %d = %d\n",x,y,s);

    dividaValores(&x,&y,&d);
    printf("\n A Divisão de %d por %d = %.2f\n",x,y,d);
}


