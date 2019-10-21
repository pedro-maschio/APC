#include <stdio.h>

typedef struct {
    int matricula;
    double p1, p2, p3;
    double t1, t2, t3, t4, t5;
} Aluno;
int main() {
    int i;
    Aluno aluno[10];
    FILE *fd, *fd2;
    double mediaFinal;
    
    if((fd = fopen("alunos.bin", "wb")) == NULL) {
        printf("Erro ao criar arquivo!");
        return 1;
    }

    for(i = 0; i < 10; i++) {
        printf("Aluno %d:\n", i+1);
        printf("Informe a matricula do aluno: ");
        scanf("%d", &aluno[i].matricula);
        printf("Informe a nota da p1: ");
        scanf("%lf", &aluno[i].p1);
        printf("Informe a nota da p2: ");
        scanf("%lf", &aluno[i].p2);
        printf("Informe a nota da p3: ");
        scanf("%lf", &aluno[i].p3);
        printf("Informe a nota da t1: ");
        scanf("%lf", &aluno[i].t1);
        printf("Informe a nota da t2: ");
        scanf("%lf", &aluno[i].t2);
        printf("Informe a nota da t3: ");
        scanf("%lf", &aluno[i].t3);
        printf("Informe a nota da t4: ");
        scanf("%lf", &aluno[i].t4);
        printf("Informe a nota da t5: ");
        scanf("%lf", &aluno[i].t5);
        printf("\n\n");
    }
    fwrite(&aluno, sizeof(Aluno), 1, fd);
    for(i = 0; i < 10; i++) {
        printf("Matricula: %d P1: %.2lf P2: %.2lf P3: %.2lf T1: %.2lf T2: %.2lf T3: %.2lf T4: %.2lf T5: %.2lf\n", 
        aluno[i].matricula, aluno[i].p1, aluno[i].p2, aluno[i].p3, aluno[i].t1, aluno[i].t2, aluno[i].t3,
        aluno[i].t4, aluno[i].t5);
    }
    fclose(fd);

    if((fd2 = fopen("media.txt", "w")) == NULL) {
        printf("Erro ao criar arquivo de medias!");
        return 1;
    }
    
    for(i = 0; i < 10; i++) {
        fread(&aluno, sizeof(Aluno), 1, fd);
        mediaFinal = (2*((aluno[i].t1+aluno[i].t2+aluno[i].t3+aluno[i].t4+aluno[i].t5)/5) +
        8*((2*aluno[i].p1) + 3*aluno[i].p2 + 3*aluno[i].p3)/8)/10 ;

        fprintf(fd2, "Matricula: %d Media final: %lf\n", aluno[i].matricula, mediaFinal);
    }

}