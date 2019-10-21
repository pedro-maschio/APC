#include <stdio.h>

typedef struct {
    char nome[100], endereco[150], telefone[14];
    char aniversario[11];
} Contatos;

int main() {
    Contatos contatos[10];
    int i;

    for(i = 0; i < 10; i++) {
        printf("Informe o seu nome: ");
        scanf("%[^\n]", contatos[i].nome);
        getchar();
        printf("Informe o seu endereco: ");
        scanf("%[^\n]", contatos[i].endereco);
        getchar();
        printf("Informe o seu telefone: ");
        scanf("%[^\n]", contatos[i].telefone);
        getchar();
        printf("Informe o seu aniversario (formato: dd/mm/aaaa): ");
        scanf("%[^\n]", contatos[i].aniversario);  
        getchar();

    }

    for(i = 0; i < 10; i++) {
        if(contatos[i].aniversario[3] == '1' && contatos[i].aniversario[4] == '2') {
            printf("\nDados do(s) aniversariante(s) em dezembro\n\n");
            printf("Nome: ");
            printf("%s", contatos[i].nome);
            printf("\n");
            printf("Endereco: ");
            printf("%s", contatos[i].endereco);
            printf("\n");
            printf("Telefone: ");
            printf("%s", contatos[i].telefone);
            printf("\n");
            printf("Aniversario: ");
            printf("%s", contatos[i].aniversario);
            printf("\n");
        }
    }
}