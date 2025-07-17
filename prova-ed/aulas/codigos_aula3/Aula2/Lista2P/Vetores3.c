#include <stdio.h>
#include <stdlib.h>

void mostraVetor(int *vt, int n){
    printf("\n [");
    for(int i=1;i<n-1;i++)
        printf(" %d, ",*(vt+i));
    printf("%d ]\n",*(vt+n-1));
}

void menorVetor(int *vt, int n, int *menor){
    int m = *(vt);
    for(int i=1;i<n;i++){
        if(m>*(vt+i))
            m = *(vt+i);
    *menor = m;
    }
}
void maiorVetor(int *vt, int n, int *maior){
    int m = *(vt);
    for(int i=1;i<n;i++){
        if(m<*(vt+i))
            m = *(vt+i);
    *maior = m;
    }
}
void maiormenorVetor(int *vt,int n, int *menor, int *maior){
    menorVetor(vt,n,menor);
    maiorVetor(vt,n,maior);
}



int* menorVetorPonteiro(int *vt, int n){
    int *menor = (int)malloc(sizeof(int));
    int m = *(vt);
    for(int i=1;i<n;i++){
        if(m>*(vt+i)){
            m = *(vt+i);
            menor = (vt+i);
        }
    }
    return menor;
    
}
int* maiorVetorPonteiro(int *vt, int n){
    int *maior = (int)malloc(sizeof(int));
    int m = *(vt);
    for(int i=1;i<n;i++){
        if(m<*(vt+i)){
            m = *(vt+i);
            maior = (vt+i);
        }
    }
    return maior;
}
void maiormenorVetorPonteiro(int *vt,int n, int **menor, int **maior){
    *(menor) = menorVetorPonteiro(vt,n);
    *(maior) = maiorVetorPonteiro(vt,n);
    //printf("\n Valor do menor elemento %d",*menor);
    //printf("\n Valor do maior elemento %d\n",*maior);
}


int main(){
    int v[10] = {4,2,-5,0,9,2,1,10,-1,0}, n=10;
    int *menor, *maior;
    mostraVetor(v,n);
    // menorVetor(v,n,&menor);
    // printf("\n Menor elemento Vetor %d",menor);
    
    // maiorVetor(v,n,&maior);
    // printf("\n Maior elemento Vetor %d\n",maior);
    
    // v[4] = 30;
    // v[6] = -15;
    // maiormenorVetor(v,n,&menor,&maior);
    // printf("\n Menor Vetor = %d maior %d \n",menor,maior);
    // mostraVetor(v,n);

    maiormenorVetorPonteiro(v,n,&menor,&maior);
    printf("\n Menor Vetor = %d maior %d \n",*menor,*maior);


    
}


