#include <stdio.h>
#include <stdlib.h>

void imprimeString(char st[],int n){
    printf("\n String normal \n");
    for(int i=0;i<n;i++)
        printf("S[%d]=%c ",i,st[i]);
    printf("\n");   
}


void imprimeStringPonteiro(char *p,int n){
    printf("\n Vetor String Ponteiro\n");
    for(int i=0;i<n;i++)
        printf("S[%d]=%c ",i,*(p+i));   
    printf("\n");
}

void codigoAsc(char *p, int n ){
    printf("\n Código ASC da STRING");
    for(int i=0;i<30;i++)
        printf("\n %c = %d ",*(p+i),*(p+i));   
    printf("\n");
}


int main(){
    char v[] ="Estrutura de Dados";
    int n = sizeof(v);
    imprimeString(v,n);
    imprimeStringPonteiro(v,n);
    codigoAsc(v,n);



    
}


