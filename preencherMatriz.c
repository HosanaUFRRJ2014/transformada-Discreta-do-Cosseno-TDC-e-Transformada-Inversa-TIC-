#include <stdio.h>

/*
Autor: Hosana Gomes
2015 - 1º semestre
UFRRJ
Álgebra Linear Computacional*/

/*Função que preenche uma matriz com os dados inseridos pelo usuário*/

void PreencherMatriz(int DIM, float matriz[][DIM])
{
    int linha, coluna;

    printf("Preencha a matriz: \n");

    for(linha = 0 ; linha < DIM ; linha++)
    {
        for(coluna = 0 ; coluna < DIM ; coluna++)
        {
            printf("Elemento [%d][%d]: ", linha+1, coluna+1);
            scanf("%f", &matriz[linha][coluna]);
        }
    }    
    
}
