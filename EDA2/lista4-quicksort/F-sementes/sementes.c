#include <stdio.h>
#include <stdlib.h>

typedef struct sem{
    unsigned long int cod;
    int nota;
} sem;



int main(void){
    int n;
    sem sementes[10000000];

    scanf("%d", &n); // Quantidade de sementes que devem ser selecionadas

    int i = 0;
    while(scanf("%ld %d", &sementes[i].cod, &sementes[i].nota) != EOF){
        i++;
    }

    return 0;
}