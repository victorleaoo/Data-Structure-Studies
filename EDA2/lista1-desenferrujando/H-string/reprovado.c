#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n, nota, menor, instancia;
    char nome[20], nome_reprovado[20];

    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        scanf(" %s", nome);
        scanf("%d", &nota);
        if(i == 0){
            menor = nota;
            strcpy(nome_reprovado, nome);
            instancia = i;
            continue;
        }
        if(nota == menor){
            if(strcmp(nome, nome_reprovado) > 0){
                instancia = i;
                strcpy(nome_reprovado, nome);
            }
        } else if (nota < menor){
            menor = nota;
            strcpy(nome_reprovado, nome);
            instancia = i;
        }
    }

    printf("Instancia %d\n", instancia);
    printf("%s", nome_reprovado);

    return 0;
}