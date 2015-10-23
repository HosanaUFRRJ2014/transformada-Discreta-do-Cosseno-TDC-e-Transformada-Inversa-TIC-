#include <stdio.h>

/*
Autor: Hosana Gomes
2015 - 1º semestre
UFRRJ
Álgebra Linear Computacional*/

void ImprimirMatriz(int DIM, float matriz[][DIM])
{
    int linha, coluna;


    for(linha = 0 ; linha < DIM ; linha++)
    {
        for(coluna = 0 ; coluna < DIM ; coluna++)
        {
            printf("%f   ", matriz[linha][coluna]);
        } 
        
        printf("\n"); //após cada linha ser impressa, um salto de linha
    }
}
