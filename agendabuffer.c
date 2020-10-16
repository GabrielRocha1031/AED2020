#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insere(void *pBuffer);
void remover(void *pBuffer);
void lista(void *pBuffer);
void busca(void *pBuffer);

int main(){
    void *pBuffer;
    pBuffer = malloc(5 * sizeof(int) + 20 * sizeof(char)); //PB Num de pessoas \ int for \ int*2 switch \ int*3 vazio \ int*4 vazio \ 20 char para nome
    *(int *)pBuffer = 0;
for(;;){
    printf("Escolha uma opcao:\n\n");
    printf("1 - Inserir\n");
    printf("2 - Remover\n");
    printf("3 - Listar\n");
    printf("4 - Buscar\n");
    printf("0 - Sair\n");
    scanf("%d", (int*)(pBuffer + sizeof(int) * 2));
    switch (*(int*)(pBuffer + sizeof(int) * 2)){
    case 1:
        insere(pBuffer);
        break;
    case 2:
        remover(pBuffer);
        break;
    case 3:
        lista(pBuffer);
        break;
    case 4:
        busca(pBuffer);
        break;
    case 0:
        exit(0);
        break;
    default:
        break;
    }
}
    free(pBuffer);
    return 0;
}

void insere(void *pBuffer){
    pBuffer = realloc(pBuffer,(5 * sizeof(int) + 20 * sizeof(char)) + ((20 * sizeof(char) + sizeof(int)) * ((*(int*)pBuffer) + 1))); //aloca mais memoria (era para fazer isso porem so adiciona 2)

    printf("Insira o nome:");
    scanf("%s",(char*)pBuffer + 5 * sizeof(int) + 20 * sizeof(char) + (20 * sizeof(char) + sizeof(int)) * (*(int*)pBuffer));

    printf("Insira o numero:");
    scanf("%d",(int*)(pBuffer + 5 * sizeof(int) + 20 * sizeof(char) + (20 * sizeof(char) + sizeof(int)) * (*(int*)pBuffer) + 20 * sizeof(char)));

    *(int*)pBuffer = *(int*)pBuffer + 1; //Aumenta o contador de pessoas

}
void lista(void *pBuffer)
{

    for((*(int*)(pBuffer + sizeof(int))) = 0; (*(int*)(pBuffer + sizeof(int))) < *(int*)pBuffer; *(int*)(pBuffer + sizeof(int)) = *(int*)(pBuffer + sizeof(int)) + 1) {
        printf("Nome: %s\n",(char*)pBuffer + sizeof(int) * 5 + 20 * sizeof(char) + (20 * sizeof(char) + sizeof(int)) * (*(int*)(pBuffer + sizeof(int))));
        printf("Numero: %d\n", *(int*)(pBuffer + (5 * sizeof(int) + 20 * sizeof(char) + 20 * sizeof(char) + ((20 * sizeof(char) + sizeof(int)) * (*(int*)(pBuffer + sizeof(int)))))));
    } 
}
void remover(void *pBuffer){
    char *nome;
    nome = (char*)malloc(20 * sizeof(char));
    scanf("%s", nome);
    for((*(int*)(pBuffer + sizeof(int))) = 0 ; (*(int*)(pBuffer + sizeof(int))) < (*(int*)pBuffer) ; (*(int*)(pBuffer + sizeof(int)) = (*(int*)(pBuffer + sizeof(int))) + 1)){
        if(strcmp((char*)pBuffer + 5 * sizeof(int) + 20 * sizeof(char) + (20 * sizeof(char) + sizeof(int)) * (*(int*)(pBuffer + sizeof(int))), nome) == 0){
            strcpy((char*)pBuffer + 5 * sizeof(int) + 20 * sizeof(char) + (20 * sizeof(char) + sizeof(int)) * (*(int*)(pBuffer + sizeof(int))), (char*)pBuffer + 5 * sizeof(int) + 20 * sizeof(char) + (20 * sizeof(char) + sizeof(int)) * (*(int*)pBuffer - 1) );
            *(int*)(pBuffer + 5 * sizeof(int) + 20 * sizeof(char) + 20 * sizeof(char) + (20*sizeof(char) + sizeof(int)) * (*(int*)(pBuffer + sizeof(int)))) = *(int*)(pBuffer + 5 * sizeof(int) + 20 * sizeof(char) + 20 * sizeof(char) + (20 * sizeof(char) + sizeof(int)) * (*(int*)pBuffer - 1));
            *(int*)pBuffer = *(int*)pBuffer - 1; //reduz o contador de pessoas
            pBuffer = realloc(pBuffer, 5 * sizeof(int) + (20 * sizeof(char) + sizeof(int)) * (*(int*)pBuffer)); //reduz o tamanho do buffer
            
        }
    }    
}
void busca(void *pBuffer){
    char *nome;
    nome = (char*)malloc(20 * sizeof(char));
    scanf("%s",nome);
    for((*(int*)(pBuffer + sizeof(int))) = 0 ; (*(int*)(pBuffer + sizeof(int))) < (*(int*)pBuffer) ; (*(int*)(pBuffer + sizeof(int)) = (*(int*)(pBuffer + sizeof(int))) + 1))
        if(strcmp((char*)pBuffer + 5 * sizeof(int) + 20 * sizeof(char) + (20 * sizeof(char) + sizeof(int)) * (*(int*)(pBuffer + sizeof(int))), nome) == 0)
            printf("Numero:%d\n", *(int*)(pBuffer + 5 * sizeof(int) + 20 * sizeof(char) + 20 * sizeof(char) + (20 * sizeof(char) + sizeof(int)) * (*(int*)(pBuffer + sizeof(int)))));
}