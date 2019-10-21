#include <stdio.h>
typedef struct {
    int cod;
    char depto[50], nome[50];
    float sal;
} Func;

int main() {
    Func funcionario;
    FILE *arquivo;
    int i = 0;
 
    if ((arquivo = fopen("funcAtualizado.bin","rb")) == NULL){
        printf("Error! opening file");
        return 1;
    }

    
    while(feof(arquivo) == 0) {
        fread(&funcionario, sizeof(Func), 1, arquivo);
        printf("%d %s %s %f\n", funcionario.cod, funcionario.nome, funcionario.depto, funcionario.sal);
        i++;
    }
    printf("\nHa um total de %d empregados\n", i);
}