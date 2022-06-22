#include <stdio.h>

void insertionsort(int *vetor, int l, int r){
    for(int i = r; i > l; i--){
        if(vetor[i] < vetor[i-1]){
            int t = vetor[i-1];
            vetor[i-1] = vetor[i];
            vetor[i] = t;
        }
    }
    for(int i = l+2; i <= r; i++){
        int j = i - 1;
        int tmp = vetor[j + 1]; //segura o valor
        while(tmp < vetor[j] && j >= 0){
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = tmp;
    }
}

int main(void){
    int v[1000], num, i = 0;

    while (scanf("%d", &num) != EOF){
        v[i] = num;
        i++;
    }

    insertionsort(v, 0, i-1);

    int j;

    for (j = 0; j < i - 1; j++){
        printf("%d ", v[j]); 
    }

    printf("%d\n", v[j]);

    return 0;
}