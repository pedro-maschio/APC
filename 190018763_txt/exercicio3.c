#include <stdio.h>
int main() {    
    FILE *fd1, *fd2;
    char filename1[50], filename2[50];

    printf("Informe o nome do arquivo (.txt e já em disco): ");
    scanf("%s", filename1);

    if((fd1 = fopen(filename1, "r+")) == NULL) {
        printf("O arquivo não existe!");
        return 1;
    }

    printf("Informe o nome do arquivo que será criado (.txt): ");
    scanf("%s", filename2);

    if((fd2 = fopen(filename2, "w")) == NULL) {
        printf("Falha ao criar o segundo arquivo!");
        return 1;
    }


    double n1, n2, n3;
    char nome[40];
    int codigo, num;
    double media;
    while(fscanf(fd1, "%d %s %d %lf %lf %lf\n", &num, nome, &codigo, &n1, &n2, &n3) != EOF) {
        media = (n1 + n2 + n3) / 3.0;
        fprintf(fd2, "%d %lf\n", codigo, media);
    }
    fclose(fd1);
    fclose(fd2);
}