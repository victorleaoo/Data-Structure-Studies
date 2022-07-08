#include <stdio.h>
#include <stdlib.h>

#define less(A, B) (A < B)
#define exch(A, B) {int t = B; B = A; A = t;}
#define cmpexch(A, B) {if(less(B, A)) exch(A, B);}

int separa(int *v, int l, int r){
    int i = l-1, j=r;
    int c = v[r];
    for(;;){
        while (less(v[++i], c));
        while(less(c, v[--j])){
            if(i == j) break; // não dar seg. fault
        }
        if(i >= j) break;
        exch(v[i], v[j]);
    }
    exch(v[i], v[r]);
    return i;
}

void quicksort(int *v, int l, int r){
    if(l >= r) return; // critério de parada
    exch(v[r-1], v[((r-l)/2) + 1]);
    cmpexch(v[l], v[r-1]); // joga o menor para left
    cmpexch(v[l], v[r]); // joga o menor para left
    cmpexch(v[r-1], v[r]); // joga o menor para r-1
    int j = separa(v, l+1, r-1);
    quicksort(v, l, j-1);
    quicksort(v, j+1, r);
}

int main(void){
    int j, i = 0, r;

    scanf("%d", &r);

    int *v = malloc(r * sizeof(int));

    for(i = 0; i < r; i++){
        scanf("%d", &v[i]);
    }

    quicksort(v, 0, i-1);

    for(j = 0; j < i - 1; j ++){
        printf("%d ", v[j]);
    }
        
    printf("%d\n", v[j]);

    free(v);
    return 0;
}