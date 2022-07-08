#include <stdio.h>
#include <stdlib.h>

#define less(A, B) (A < B)
#define exch(A, B) {int t = B; B = A; A = t;}
#define cmpexch(A, B) {if(less(B, A)) exch(A, B);}

int separa(int *v, int l, int r){
  int tam = r - l + 1, j;
  int c = v[r];
  int *menores = malloc(sizeof(int) * tam);
  int *maiores = malloc(sizeof(int) * tam);
  int iMenor = 0, iMaior = 0, i;
  int cPos;

  for (i = l; i < r; i++) {
    if (less(v[i], c)) {
      menores[iMenor++] = v[i];
    } else {
      maiores[iMaior++] = v[i];
    }
  }

  i = l;

  for (j = 0; j < iMenor; j++) {
    v[i++] = menores[j];
  }

  v[i] = c; // pivor
  cPos = i;
  i++;

  for (j = 0; j < iMaior; j++) {
    v[i++] = maiores[j];
  }

  free(menores);
  free(maiores);

  return cPos;
}

void quicksort(int *v, int l, int r){
  if(l > r) return; // critério de parada
  
  int j = separa(v, l, r);
  
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