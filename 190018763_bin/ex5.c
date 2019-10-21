#include <stdio.h>
typedef struct {
    int cod;
    char depto[50], nome[50];
    float sal;
} Func;
int main() {
    FILE *arq;
    FILE *arq2;
    Func funcionario;
    int codigo, flag = 0;
    double salario;

    if((arq = fopen("funcionarios.bin", "rb")) == NULL) {
        printf("Houve um erro na leitura!");
        return 1;
    }
    if((arq2 = fopen("funcionarios2.bin", "wb")) == NULL) {
        printf("Houve um erro na abertura do arquivo!");
        return 1;
    }

    printf("Informe o codigo do funcionario: ");
    scanf("%d", &codigo);

    while(fread(&funcionario, sizeof(Func), 1, arq)) {
        if(funcionario.cod == codigo) {
            printf("Informe o novo salario: ");
            scanf("%lf", &salario);
            flag = 1;
            funcionario.sal = salario;
            fwrite(&funcionario, sizeof(Func), 1, arq2);

            while(fread(&funcionario, sizeof(Func), 1, arq)) 
                fwrite(&funcionario, sizeof(Func),  1, arq2);
        }
    }

    if(flag == 0)
        printf("O funcionario procurado nao esta no arquivo!");


}  