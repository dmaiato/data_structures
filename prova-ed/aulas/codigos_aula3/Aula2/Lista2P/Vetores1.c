#include <stdio.h>
#include <stdlib.h>

void imprimeVetor(int vt[],int n){
    printf("\n Vetor normal \n");
    for(int i=0;i<n;i++)
        printf(" vt[%d]=%d",i,vt[i]);
    printf("\n");   
}


void imprimeVetorPonteiro(int *p,int n){
    printf("\n Vetor Ponteiro");
    for(int i=0;i<n;i++)
        printf(" vt[%d]=%d",i,*(p+i));   
    printf("\n");
}

void somaDez(int vt[], int n ){
    printf("\n Soma 10 ao vetor");
    for(int i=0;i<n;i++)
        vt[i] += 10;   
}

void somaDezPonteiro(int *p, int n ){
    printf("\n Soma 10 ao vetor Ponteiro");
    for(int i=0;i<n;i++)
        *(p+i) += 10;   
}

int main(){
    int v[5] = {3,4,5,2,1}, n=5;
    imprimeVetor(v,n);
    imprimeVetorPonteiro(v,n);
    printf("\n");
    somaDez(v,n);
    somaDezPonteiro(v,n);
    imprimeVetor(v,n);




    
}


