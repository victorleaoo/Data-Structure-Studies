#include <stdio.h>

void selectionsort(int *vetor, int l, int r){
    for (int i = l; i < r; i++)
    {
        int min = i;
        for (int j = i + 1; j <= r; j++)
            if (vetor[j] < vetor[min])
                min = j;
        int t = vetor[i];
        vetor[i] = vetor[min];
        vetor[min] = t;
    }
}

int main(void){
    int v[1000], num, i = 0;

    while (scanf("%d", &num) != EOF){
        v[i] = num;
        i++;
    }

    selectionsort(v, 0, i-1);

    int j;

    for (j = 0; j < i - 1; j++){
        printf("%d ", v[j]); 
    }

    printf("%d\n", v[j]);

    return 0;
}