//Gabriel Rocha Silveira
//AED 2020 AULA 2 SLIDE 28

#include <stdio.h>
#include <stdlib.h>

struct Pessoa{
    char nome[30];
    int idade;
    int altura;
};
typedef struct Pessoa Pessoa;

void *adiciona(Pessoa *p, int n);
void imprime(Pessoa *p, int n);


int main(){
Pessoa *p;
p = (Pessoa*)malloc(sizeof(Pessoa));
 if(!p){
     printf("ERRO! Memoria insuficiente!!! \n");
     exit(1);
     }

int op, n;
n = 0;
    do{
    printf("Escolha uma opcao:\n  1 - Adicionar pessoas\n  0 - Sair e imprimir\n");
    scanf("%d", &op);
    switch(op){
        case 1:
        n = n+1;
        p = adiciona(p, n);
        break;
        case 0:
        printf("\nImprimindo...\n\n");
        imprime(p, n);
        free (p);
        break;
        default:
        printf("\nOpcao invalida!\n");
        break;
    }
    }while(op!=0);
return 0;
}

void *adiciona(Pessoa *p, int n){
    p = (Pessoa*)realloc(p, sizeof(Pessoa));
    printf("\nNome: ");
    scanf("%s", (p+(n-1))->nome);
    printf("\nIdade: ");
    scanf("%d", &(p+(n-1))->idade);
    printf("\nAltura: ");
    scanf("%d", &(p+(n-1))->altura);
    return p;
}

void imprime(Pessoa *p, int n){
    for(int i=0 ; i < n ; i++){
        printf("Nome: %s\n", (p+i)->nome);
        printf("Idade: %d\n", (p+i)->idade);
        printf("Altura: %d\n\n", (p+i)->altura);
    }
}
