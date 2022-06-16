#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, frequencia, ja[100000], no_vetor = 0, frequencia_dada;

    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        frequencia_dada = 0;
        scanf("%d", &frequencia);
        if(i == 0){
            ja[i] = frequencia;
            no_vetor++;
            continue;
        }
        for (int j = 0; j < no_vetor; j++){
            if(frequencia == ja[j]){
                frequencia_dada = 1;
                break;
            }
        }
        if(frequencia_dada == 0){
            ja[i] = frequencia;
            no_vetor++;
        }
    }
    
    printf("%d", no_vetor);

    return 0;
}