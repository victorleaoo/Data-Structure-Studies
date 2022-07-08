#include <stdio.h>
#include <stdlib.h>

#define less(A,B) (A < B)

// a e b ordenados
int *intercala(int *a, int la, int ra, int *b, int lb, int rb){
    int ta = (ra-la+1);
    int tb = (rb-lb+1);

    int *c = malloc((ta+tb+2)*sizeof(int));

    int lc = 0, rc = (ta+tb-1);

    int ia = la, ib = lb, ic = 0;

    while (ia <= ra && ib <= rb){
        if(less(a[ia], b[ib])){
            c[ic++] = a[ia++];
        } else{
            c[ic++] = b[ib++];
        }
    }

    while (ia <= ra){
        c[ic++] = a[ia++];
    }
    while (ib <= rb){
        c[ic++] = b[ib++];
    }

    return c;
}

void merge(int *vetor, int l, int m, int r){
    int l1 = l, r1 = m, l1i = l1;
    int l2 = m+1, r2 = r, l2i = l2;

    int *c = malloc((r-l+1)*sizeof(int));
    int ci = 0;

    int rc = r-l;

    while (l1i <= r1 && l2i <= r2){
        if(less(vetor[l1i], vetor[l2i])){
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

int buscaBinaria(int *vetor, int r, int valor) {
    int e = -1, d = r, m;

    while (e < d - 1) {
        m = (e + d)/2;

        if (vetor[m] < valor){
            e = m;
        } else{
            d = m;
        } 
    }

    if(vetor[d] == valor){
        return 1;
    } else{
        return -1;
    }
}

int main(void){
    int n, v[200000];

    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    mergesort(v, 0, n-1);

    // Remover repetidos - Vai criar um "novo vetor" somente com os números que não repetem
    int novoi = 0;
    for(int i = 1; i < n; i++){
        if(v[i] != v[novoi]){
            v[++novoi] = v[i];
        }
    }

    int novor = novoi;

/* Imprimir o Vetor
    for(int i = 0; i < novor+1; i++){
        printf("%d", v[i]);
    }
*/

    if(novor % 2 == 0){ // Sempre começa em 0 o vetor
        v[++novor] = 1000000000;
    }

    // Calcular NMU
    int nmu[66000], nmui = -1;
    for(int i = 0; i < novor; i+=2){
        nmu[++nmui] = v[i] + v[i+1];
        if(buscaBinaria(v, novor, nmu[nmui]) != -1){ // Se encontrar, não coloca no vetor
            nmui--;
        }
    }

    // Inserção no vetor
    int *c = intercala(v, 0, novor, nmu, 0, nmui);

    for(int i = 0; i <= (novor + nmui+2); i+=4){
        printf("%d\n", c[i]);
    }
    
    printf("Elementos: %d\n", (novor+nmui+2));

    return 0;    
}