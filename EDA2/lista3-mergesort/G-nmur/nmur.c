#include <stdio.h>
#include <stdlib.h>

#define less(A,B) (A < B)
#define lesseq(A,B) (A <= B)

void merge(int *vetor, int l, int m, int r){
    int l1 = l, r1 = m, l1i = l1;
    int l2 = m+1, r2 = r, l2i = l2;

    int *c = malloc((r-l+1)*sizeof(int));
    int ci = 0;

    int rc = r-l;

    while (l1i <= r1 && l2i <= r2){
        if(lesseq(vetor[l1i], vetor[l2i])){
            c[ci++] = vetor[l1i++];
        } else{
            c[ci++] = vetor[l2i++];
        }
    }
    
    while (l1i <= r1){
        c[ci++] = vetor[l1i++];
    }
    while (l2i <= r2){
        c[ci++] = vetor[l2i++];
    }
    
    l1i = l;
    for(ci=0; ci <= rc; ci++){
        vetor[l1i++] = c[ci];
    }

    free(c);
}

void mergesort(int *vetor, int l, int r){
    if (l >= r) return;
    int meio = (r - l)/2 + l;
    mergesort(vetor, l, meio);
    mergesort(vetor, meio+1, r);
    merge(vetor, l, meio, r); // junta os dois vetores
}

void intercala(int *v1, int r1, int *v2, int r2)
{
    int *c = malloc((r1 + r2) * sizeof(int));
    int i = 0, j = 0, k = 0;
    for (; i < r1 && j < r2; k++)
    {
        if (v1[i] <= v2[j]){
            c[k] = v1[i++];
        } else{
            c[k] = v2[j++];
        }  
    }

    while (i < r1){
        c[k++] = v1[i++];
    }
    while (j < r2){
        c[k++] = v2[j++];
    }

    k = 0;
    for (i = 0; i < (r1 + r2); i++){
        v1[i] = c[k++];
    }  

    free(c);
}

int removeRepetidos(int *v, int n){
    int j = 1;
    
    for (int i = 1; i < n; i++){
        if (v[i] != v[j - 1]){
            v[j++] = v[i];
        }
    }

    return j;
}

// Adiciona no final do vetor
int calculaNMU(int *v, int n){
    int j = 0;
    
    for(int i = 0; i < n - 1; i+=2){
        v[n + j++] = v[i] + v[i+1];
    }

    return j;
}

int main(void){
    int n;

    scanf("%d", &n);

    int *v = malloc(sizeof(int) * (2*n));

    for (int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    mergesort(v, 0, n-1);

    // N é o tamanho do novo vetor
    int tam = removeRepetidos(v, n);

    if(tam % 2 != 0){ // Sempre começa em 0 o vetor
        v[tam++] = 1000000000;
    }

    int novor = calculaNMU(v, tam);

    // Junta o final do vetor (inseridos) com o vetor sem os repetidos
    intercala(v, tam, v + tam, novor); 

    tam = removeRepetidos(v, tam+novor);

    for(int i = 0; i <= tam; i+=4){
        printf("%d\n", v[i]);
    }
    
    printf("Elementos: %d\n", tam);

    return 0;    
}