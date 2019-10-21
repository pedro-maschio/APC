#include <stdio.h>

typedef struct {
    int cod;
    char depto[50], nome[50];
    float sal;
} Func;

int main() {
    Func funcionario;
    FILE *arquivo;
    char opcao;

    if((arquivo = fopen("funcionarios.bin", "wb")) == NULL) {
        printf("Erro ao gerar arquivo binario!");
        return 1;
    }

    do {
        printf("Informe o codigo do funcionario: ");
        scanf("%d", &funcionario.cod);
        printf("Informe o nome do funcionario: ");
        scanf("%s", funcionario.nome);
        printf("Informe o departamento do funcionario: ");
        scanf("%s", funcionario.depto);
        printf("Informe o salario do funcionario: ");
        scanf("%f", &funcionario.sal);

        fwrite(&funcionario, sizeof(Func), 1, arquivo);
        
        getchar();
        printf("Deseja cadastrar mais dados? (S para sim N para nao): ");
        scanf("%c", &opcao);
        printf("\n");
        
        
    } while(opcao != 'N');

    fclose(arquivo);
}