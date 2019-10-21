#include <stdio.h>
typedef struct {
    int codigo;
    char nome[21];
} Profissoes;

int main() {
    int i, n, cod;

    printf("Quantas profissoes voce deseja inserir?");
    scanf("%d", &n);

    Profissoes profissoes[n];

    for(i = 0; i < n; i++) {
        printf("Informe o codigo: ");
        scanf("%d", &profissoes[i].codigo);
        printf("Informe o nome da profissao: ");
        getchar();
        scanf("%[^\n]", profissoes[i].nome);
        getchar();
        printf("\n");
    }
    
    printf("\nInforme o codigo da profissao desejada: ");
    scanf("%d", &cod);

    for(i = 0; i < n; i++) {
        if(profissoes[i].codigo == cod)
            printf("Nome da profissao: %s\n", profissoes[i].nome);
    }

    return 0;
}