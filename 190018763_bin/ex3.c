#include <stdio.h>
typedef struct {
    int cod;
    char depto[50], nome[50];
    float sal;
} Func;

int main() {
    FILE *arquivo;
    Func funcionario;
    int i = 0;

    if((arquivo = fopen("funcionarios.bin", "rb")) == NULL) {
        printf("Erro ao gerar arquivo binario!");
        return 1;
    }


    while(fread(&funcionario, sizeof(Func), 1, arquivo)) {
        printf("%d %s %s %f\n", funcionario.cod, funcionario.nome, funcionario.depto, funcionario.sal);
        i++;
    }
    printf("\nHa um total de %d empregados.\n", i);
    fclose(arquivo);
}