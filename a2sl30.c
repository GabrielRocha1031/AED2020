//Gabriel Rocha Silveira
//AED 2020 AULA 2 SLIDE 30

#include <stdio.h>
#include <stdlib.h>

int **criaMatriz(int m, int n);
void leiaMatriz(int **mat, int m, int n);
int somaMatriz(int **mat, int m, int n);
int *colunaMatriz(int **mat, int m, int n, int ncoluna);
void liberaMatriz(int **mat, int ncoluna);
void imprimeMatriz(int **mat, int m, int n);
void imprimeVetor(int *vet, int n);

int main(){
    int m, n, op, **mat, soma, ncoluna, *vet;
    

    do{
        printf("Escolha uma opcao:\n\n");
        printf("1 - Criar ou redimensionar matriz\n");
        printf("2 - Informar elementos da matriz\n");
        printf("3 - Soma dos elementos\n");
        printf("4 - Retornar coluna da matriz\n");
        printf("5 - Imprimir matriz\n");
        printf("6 - SAIR\n");
        scanf("%d", &op);
        switch(op){
            case 1:
            printf("Informe a quantidade de linhas e colunas:\n");
            scanf("%d", &m); //linhas
            scanf("%d", &n); //colunas
            mat = criaMatriz(m, n);
            break;
            case 2:
            leiaMatriz(mat, m, n);
            break;
            case 3:
            soma = somaMatriz(mat, m, n);
            printf("A soma dos elementos eh: %d\n", soma);
            break;
            case 4:
            printf("Informe a coluna que deseja por no vetor: ");
            scanf("%d", &ncoluna);
            vet = colunaMatriz(mat, m, n, ncoluna);
            imprimeVetor(vet, n);
            break;
            case 5:
            imprimeMatriz(mat, m, n);
            break;
            case 6:
            liberaMatriz(mat, m);
            free(vet);
            free(mat);
            exit (0);
            break;
        }

    }while (op != 6);

    return 0;
}

int **criaMatriz(int m, int n){
    int **mat;
    mat = (int**)malloc(m * sizeof(int*)); // Alocando linhas
    for(int i=0 ; i<m ; i++){
        mat[i] = (int*)malloc(n * sizeof(int)); //Alocando colunas
    }
    return mat;
}

void leiaMatriz(int **mat, int m, int n){
    int i, j;
    for(i=0 ; i<m ; i++){
        for(j=0 ; j<n ; j++){
            printf("Elemento, linha %d, Coluna %d\n", i,j);
            scanf("%d", &mat[i][j]);
        }
    }
}

int somaMatriz(int **mat, int m, int n){
    int i, j, soma=0;
    for(i=0 ; i<m ; i++){
        for(j=0 ; j<n ; j++){
            soma = soma + mat[i][j];
        }
    }
    return soma;
}

int *colunaMatriz(int **mat, int m, int n, int ncoluna){
    int *vet, i;
    vet = (int*)malloc(m * sizeof(int));
    for(i = 0 ; i<n ; i++){
        vet[i] = mat[i][ncoluna];
    }
    return vet;
} 

void liberaMatriz(int **mat, int m){
    int i;
    for(i = 0; i < m; i++)
		free(mat[i]);
}

void imprimeMatriz(int **mat, int m, int n){
    int i, j;
    for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
			printf("%d\t", mat[i][j]);
		printf("\n");
	}
}

void imprimeVetor(int *vet, int n){
    int i;
    for(i=0 ; i<n ; i++){
        printf("%d\t", vet[i]);
    }
}