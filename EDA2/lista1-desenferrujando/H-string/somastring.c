#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, *soma;
    char string[100];

    scanf("%d", &n);

    soma = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++){
        soma[i] = 0;
        int cont = 0;
        scanf(" %s", string);
        while(string[cont] != '\n'){
            if(string[cont] > 48 && string[cont] <= 57){
                soma[i] += (string[cont]) - '0';
            }
            cont++;
        }
    }

    for (int i = 0; i < n; i++){
        printf("%d\n", soma[i]);
    }
    return 0;
}