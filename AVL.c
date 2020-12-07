//Gabriel Rocha Silveira
//AED 2020 Semana 7 Arvore AVL
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no{
    int valor;
    struct no *esq;
    struct no *dir;
    int h;
}no;

no *esquerda(no *p);
no *direita(no *p);
no *esquerdadireita(no *p);
no *direitaesquerda(no *p);
no *insere(no *raiz, int val);
no *inicializa();
int altura (no *p);
no *criaNo(int val);
int EhArvoreAvl(no *pRaiz);
no *arv_libera(no *raiz);


int main(){
    no *raiz = inicializa();
    int n, valor, ok;
    printf("Informe o numero de elementos que deseja: ");
    scanf("%d", &n);
    srand(time(0));
    for(int i = 0 ; i<n ; i++){
        //scanf("%d", &valor); // Utilizado para efetuar os testes do segundo cenario (efetuando os testes, percebe-se uma AVL correta)
        valor = (rand() % 100);
        raiz = insere(raiz, valor);
    }
    ok = EhArvoreAvl(raiz);
    if(ok == 1)
        printf("Deu bom, sua AVL estah OK!\n");
    else
        printf("IHH deu ruim, sua AVL estah desbalanciada!!!\n");
    
    raiz = arv_libera(raiz); //Libera a memoria 
    return 0;
}

no *inicializa(){
    return (NULL);
}

int altura (no *p){
    if (!p) return(-1);
    return(p->h);
}

no *criaNo(int val){
    no *novoNo;
    novoNo = (no*)malloc(sizeof(no));
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->valor = val;
    novoNo->h = 0;
    return (novoNo);
}

// Rotacoes simples {
no *esquerda(no *p){ 
    no *aux;
    aux = p->dir;
    p->dir = aux->esq;
    aux->esq = p;
    if(altura(p->dir) >= altura(p->esq)){
        p->h = altura(p->dir) + 1;
    }else{
        p->h = altura(p->esq) + 1;
    }
    if(altura(aux->dir) >= p->h){
        aux->h = altura(aux->dir) + 1;
    }else{
        aux->h = p->h + 1;
    }
    return (aux);
}

no *direita(no *p){
    no *aux;
    aux = p->esq;
    p->esq = aux->dir;
    aux->dir = p;
    if(altura(p->dir) >= altura(p->esq)){
        p->h = altura(p->dir) + 1;
    }else{
        p->h = altura(p->esq) + 1;
    }
    if(altura(aux->dir) >= p->h){
        aux->h = altura(aux->esq) + 1;
    }else{
        aux->h = p->h + 1;
    }
}
// } Rotacoes simples

// Rotacoes duplas {
no *esquerdadireita (no *p){
    p->esq = esquerda(p->esq);
    return (direita(p));
}

no *direitaesquerda (no *p){
    p->dir = direita(p->dir);
    return (esquerda(p));
}
// } Rotacoes duplas

// Insere {
no *insere(no *raiz, int val){
    if(!raiz)
    return criaNo(val);
    if(val < raiz->valor){ 
        raiz->esq = insere(raiz->esq, val);
        if(altura(raiz->esq) - altura(raiz->dir) == 2){
            if(val < raiz->esq->valor)
                raiz = direita(raiz);
            else
                raiz = esquerdadireita(raiz);
        }else{}
    }
        if(val > raiz->valor){
            raiz->dir = insere(raiz->dir, val);
            if(altura(raiz->dir) - altura(raiz->esq) == 2){
                if(val > raiz->dir->valor)
                    raiz = esquerda(raiz);
                else
                    raiz = direitaesquerda(raiz);
            }else{}
        }
    if(altura(raiz->dir) >= altura(raiz->esq)){
        raiz->h = altura(raiz->dir) + 1;
    }else{
        raiz->h = altura(raiz->esq) + 1;
    }
    return raiz;            
}
// } Insere

// Testa se estah balanceada
int EhArvoreAvl(no *pRaiz){
    int fb;
    if (pRaiz == NULL)
        return 1;
    if (!EhArvoreAvl(pRaiz->esq))
        return 0;
    if (!EhArvoreAvl(pRaiz->dir))
        return 0;
    fb = (altura(pRaiz->esq) - altura(pRaiz->dir));
    if ( ( fb > 1 ) || ( fb < -1) )
        return 0;
    else
        return 1;
}

// Libera memoria
no *arv_libera(no *raiz){
    if (raiz != NULL){
        arv_libera(raiz->esq); 
        arv_libera(raiz->dir); 
        free(raiz);
    }
    return NULL;
}