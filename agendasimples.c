#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa{
    char nome[30];
    struct pessoa *prox;
};
typedef struct pessoa agenda;

void insere(agenda *p);
void lista(agenda *p);
void remover(agenda *p);

int main(){
agenda *start;
int op=0;
start = (agenda*)malloc(sizeof(agenda));
start->prox=NULL;

do{
    printf("Escolha uma opcao:\n\n");
    printf("1 - Inserir nome\n");
    printf("2 - Listar nomes\n");
    printf("3 - Apagar nome\n");
    printf("0 - SAIR\n");
    scanf("%d", &op);
    switch (op){
        case 1:
        insere(start);
        break;
        case 2:
        lista(start);
        break;
        case 3:
        remover(start);
        break;
        case 0:
        break;
        default:
        printf("Opcao inexistente!\n");
        break;
    };
}while (op != 0);
    return 0;
}

void insere(agenda *p){
    agenda *new;
    while(p->prox!=NULL){
        p=p->prox;
    }
    new=(agenda*)malloc(sizeof(agenda));
    printf("Informe o nome que deseja adicionar:\n"); 
    scanf("%s", new->nome);
    printf("Nome adicionado com sucesso! \n \n"); 
    new->prox=p->prox;
    p->prox=new;
}

void lista(agenda *p){
    p=p->prox;
    while(p != NULL){
       printf("%s \n", p->nome);
       p=p->prox;
    }
}

void remover(agenda *p){
    char nomep[30];
    int comp;
    printf("Informe o nome que deseja excluir: \n");
    scanf("%s", nomep);
    agenda *prev=p;
    p=p->prox;
    while(p != NULL){
       comp = strcmp(nomep, p->nome);
       if(comp==0){
           prev->prox=p->prox;
       }else{}
       prev=prev->prox;
       p=p->prox;
    }
}
