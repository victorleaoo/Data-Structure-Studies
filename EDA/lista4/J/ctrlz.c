#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula{
	char dado[200];
	struct celula *prox;
} celula;

celula *cria_pilha(){
	celula *topo = malloc(sizeof(celula));
	topo -> prox = NULL;
	return topo;
}

int empilha(celula *topo, char *str){
	int i;
	celula *novo = malloc(sizeof(celula));
	if(novo == NULL) return 0;

	for(i = 0; str[i] != '\0'; i++){
		novo -> dado[i] = str[i];
	}
	novo -> dado[i] = '\0';

	novo -> prox = topo -> prox;
	topo -> prox = novo;
	return 1;
}

int desempilha(celula *topo, char *y){
	int i;

	celula *lixo = topo -> prox;
	if (lixo == NULL){
		y[0] = 'N';
		y[1] = 'U';
		y[2] = 'L';
		y[3] = 'L';
		y[4] = '\0';
		return 0;
	}

	for(i = 0; lixo -> dado[i] != '\0'; i++){
		y[i] = lixo -> dado[i];
	}
	y[i] = '\0';

	topo -> prox = lixo -> prox;
	free(lixo);
	return 1;
}

int main(){
	celula *p = cria_pilha();
	char *string = malloc(200*sizeof(char));
	char *ioud = malloc(100*sizeof(char));
	char *entrada = malloc(200*sizeof(char));
	char *y = malloc(200*sizeof(char));

	while(scanf(" %[^\n]s", string) != EOF){
		int i;
		for(i = 0; i < 8; i++){
			ioud[i] = string[i];
		}
		ioud[i] = '\0';
		if(!strcmp(ioud, "desfazer")){
			desempilha(p, y);
			printf("%s\n", y);
		} else if (!strcmp(ioud, "inserir ")){
			int j;
			for(j = 8; string[j] != '\0'; j++){
				entrada[j-8] = string[j];
			}
			entrada[j-7] = '\0';
			empilha(p, entrada);
		} else{
			printf("NULL\n");
		}
	}
	free(string);
	free(ioud);
	free(entrada);
}