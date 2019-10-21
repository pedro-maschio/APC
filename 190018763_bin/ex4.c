#include <stdio.h>
typedef struct {
    int cod;
    char depto[50], nome[50];
    float sal;
} Func;

int main() {
    FILE *arquivo, *arqAtualizado;
    Func funcionario;

    if((arquivo = fopen("funcionarios.bin", "rb")) == NULL) {
        printf("Erro ao ler arquivo binario!");
        return 1;
    }
    if((arqAtualizado = fopen("funcAtualizado.bin", "wb")) == NULL) {
        printf("Erro ao gerar arquivo binario!");
        return 1;
    }

    while(feof(arquivo) == 0) {
        fread(&funcionario, sizeof(Func), 1, arquivo);
        if(funcionario.sal >= 5000) {
            funcionario.sal = funcionario.sal + (0.10*funcionario.sal);
            fwrite(&funcionario, sizeof(Func), 1, arqAtualizado);
        } else if(funcionario.sal <= 1000) {
            funcionario.sal = funcionario.sal + (0.30*funcionario.sal);
            fwrite(&funcionario, sizeof(Func), 1, arqAtualizado);
        } else {
            funcionario.sal = funcionario.sal + (0.20*funcionario.sal);
            fwrite(&funcionario, sizeof(Func), 1, arqAtualizado);
        }
    }
    fclose(arquivo);    
}