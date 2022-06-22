#include <stdio.h>

void insertionslow(int *vetor, int l, int r){
    for(int i = l+1; i <= r; i++){
        for(int j = i; j > l; j--){
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

    insertionslow(v, 0, i-1);

    int j;

    for (j = 0; j < i - 1; j++){
        printf("%d ", v[j]); 
    }

    printf("%d\n", v[j]);

    return 0;
}