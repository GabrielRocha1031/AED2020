//Gabriel Rocha Silveira
//AED 2020 AULA 2 SLIDE 27

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void *realocar(void *p, int n, int size);

int main(){
    void *p;
    int n, op, size;
    n=0;
    //p = malloc(sizeof(int));
    //if(!p){
    //    printf("ERRO! Falta memória!");
    //    return -1;
    //}
    do{
        printf("Escolha uma opcao:\n \n 1 - Aumentar ou reduzir espaco de memoria\n 0 - Sair\n");
        scanf("%d", &op);
        switch(op){
            case 1:
            size=n;
            printf("Informe o tamanho de espaço que deseja alocar: ");
            scanf("%d", &n);
            if(n >= 0){
            p = realocar(p, n, size);
            break;    
            }else{
            printf("\nO valor deve ser maior ou igual a 0!\n");
            break;       
            }
            case 0:
            free(p);
            exit(0);
            break;
            default:
            printf("\nOpcao invalida!\n");
            break;
        }
    }while(op != 0);
    return 0;
}

void *realocar(void *p, int n, int size){
    void *new;
    new = malloc(n);
    if(!new){
        printf("ERRO! Falta memória!");
        return -1;
    }
    memcpy(new,p,size);
    return new;
}
