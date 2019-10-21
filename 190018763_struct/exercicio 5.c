#include <stdio.h>
typedef struct {
    char nome[30], cargo[20], departamento[30], admissao[12];
    double salario;
} Funcionarios;

int main() {
    int i, n, cod;
    double media, soma;

    printf("Quantos funcionarios voce deseja cadastrar?");
    scanf("%d", &n);

    Funcionarios funcionario[n];

    for(i = 0; i < n; i++) {
        getchar();

        printf("Informe o nome: ");
        scanf("%[^\n]", funcionario[i].nome);

        printf("Informe o cargo: ");
        getchar();
        scanf("%[^\n]", funcionario[i].cargo);

        getchar();
        printf("Informe o departamento: ");
        scanf("%[^\n]", funcionario[i].departamento);

        getchar();
        printf("Informe o salario: ");
        scanf("%lf", &funcionario[i].salario);

        getchar();
        printf("Informe a data de admissao: ");
        scanf("%[^\n]", funcionario[i].admissao);

        printf("\n");

        soma += funcionario[i].salario;
    }

    media = soma / n;

    for(i = 0; i < n; i++) {
        if(funcionario[i].salario > media) {
            printf("\nNome: %s\n", funcionario[i].nome);
            printf("Cargo: %s\n", funcionario[i].cargo);
            printf("Departamento: %s\n", funcionario[i].departamento);
            printf("Data de admissao: %s\n\n", funcionario[i].admissao);
        }
    }
    

    return 0;
}