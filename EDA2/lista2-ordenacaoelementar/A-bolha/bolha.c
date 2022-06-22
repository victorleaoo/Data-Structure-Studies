#include <stdio.h>

void bubblesort(int *vetor, int l, int r){
    for(int i = l; i < r; i++){
        for(int j = l+1; j <= r; j++){
            if(vetor[j] < vetor[j-1]){
                int t = vetor[j-1];
                vetor[j-1] = vetor[j];
                vetor[j] = t;
            }
        }
    }
}

int main(void){
    int v[1000], num, i = 0;

    while (scanf("%d", &num) != EOF){
        v[i] = num;
        i++;
    }

    bubblesort(v, 0, i-1);

    int j;

    for (j = 0; j < i - 1; j++){
        printf("%d ", v[j]); 
    }

    printf("%d\n", v[j]);

    return 0;
}