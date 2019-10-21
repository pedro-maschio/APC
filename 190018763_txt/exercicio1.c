#include <stdio.h>
typedef struct {
    float n1, n2, n3;
} Alunos;
int main() {
    char filename[100];
    int n, i;

    FILE *fd;

    printf("Informe o nome do arquivo: ");
    scanf("%s", filename);

    if((fd = fopen(filename, "w")) == NULL) {
        printf("Falha ao abrir aquivo");
        return 1;
    }

    printf("Informe o numero de alunos: ");
    scanf("%d", &n);

    Alunos alunos[n];

    for(i = 0; i < n; i++) {
        printf("\n\nAluno %d:\n", i+1);
        printf("Informe a primeira nota: ");
        scanf("%f", &alunos[i].n1);
        printf("Informe a segunda nota: ");
        scanf("%f", &alunos[i].n2);
        printf("Informe a terceira nota: ");
        scanf("%f", &alunos[i].n3);

        fprintf(fd, "Aluno %d:\nNota 1: %f Nota 2: %f Nota 3: %f\n\n", i+1, alunos[i].n1, alunos[i].n2, alunos[i].n3);
    }
    printf("\nDados Informados: \n\n");
    for(i = 0; i < n; i++) {
        printf("\n\nAluno %d:\n", i+1);
        printf("Primeira nota: %f\n", alunos[i].n1);
        printf("Segunda nota: %f\n", alunos[i].n2);
        printf("Terceira nota: %f\n", alunos[i].n3);
    }
    fclose(fd);
}