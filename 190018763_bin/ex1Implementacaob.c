#include <stdio.h>

typedef struct {
    int matricula;
    double p1, p2, p3;
    double t1, t2, t3, t4, t5;
} Aluno;
int main() {
    int i;
    Aluno aluno;
    FILE *fd;
    
    if((fd = fopen("alunos.bin", "wb")) == NULL) {
        printf("Erro ao criar arquivo!");
        return 1;
    }

    for(i = 0; i < 10; i++) {
        printf("Aluno %d:\n", i+1);
        printf("Informe a matricula do aluno: ");
        scanf("%d", &aluno.matricula);
        printf("Informe a nota da p1: ");
        scanf("%lf", &aluno.p1);
        printf("Informe a nota da p2: ");
        scanf("%lf", &aluno.p2);
        printf("Informe a nota da p3: ");
        scanf("%lf", &aluno.p3);
        printf("Informe a nota da t1: ");
        scanf("%lf", &aluno.t1);
        printf("Informe a nota da t2: ");
        scanf("%lf", &aluno.t2);
        printf("Informe a nota da t3: ");
        scanf("%lf", &aluno.t3);
        printf("Informe a nota da t4: ");
        scanf("%lf", &aluno.t4);
        printf("Informe a nota da t5: ");
        scanf("%lf", &aluno.t5);
        printf("\n\n");
        fwrite(&aluno, sizeof(Aluno), 1, fd);
    }
    fclose(fd);
    
    if((fd = fopen("alunos.bin", "rb")) == NULL) {
        printf("Erro ao criar arquivo!");
        return 1;
    }
    

    for(i = 0; i < 10; i++) {
        fread(&aluno, sizeof(Aluno), 1, fd);
        printf("Matricula: %d P1: %.2lf P2: %.2lf P3: %.2lf T1: %.2lf T2: %.2lf T3: %.2lf T4: %.2lf T5: %.2lf\n", 
        aluno.matricula, aluno.p1, aluno.p2, aluno.p3, aluno.t1, aluno.t2, aluno.t3,
        aluno.t4, aluno.t5);
    }
    
    fclose(fd);

}