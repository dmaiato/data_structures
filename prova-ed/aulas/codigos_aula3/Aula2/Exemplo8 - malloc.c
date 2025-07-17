#include <stdio.h>
#include <stdlib.h>

int main(){
    int *px, *py, aux;

    //malloc - alocação dinâmica de memória para 1 inteiro
    px = (int*)malloc(sizeof(int)); 
    py = (int*)malloc(sizeof(int)); 
    
    *px = 10;
    *py = 20;

    printf("\n PX = %d e PY = %d\n",*px,*py);

    //libera memória
    free(px);
    free(py); 

}

