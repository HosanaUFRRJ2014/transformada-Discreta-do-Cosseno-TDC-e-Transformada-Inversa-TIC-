#include <stdio.h>

/*
Autor: Hosana Gomes
2015 - 1º semestre
UFRRJ
Álgebra Linear Computacional*/

/*Função que preenche um vetor coluna com os dados inseridos pelo usuário*/

void PreencherVetor(int DIM, float vetor[])
{
	int coluna;
	
	for (coluna = 0; coluna < DIM; coluna++)
	{
		printf("Elemento[%d]:\n", coluna+1);
		scanf("%f", &vetor[coluna]);

	}

}
