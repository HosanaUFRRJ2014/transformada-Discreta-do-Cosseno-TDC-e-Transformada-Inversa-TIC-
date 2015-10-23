#include <stdio.h>

/*Função para imprimir um vetor*/

void ImprimirVetor(int DIM, float vetor[])
{

    int coluna;   //vetor "em pé"

    printf("\nVetor:\n\n");

	for (coluna = 0; coluna < DIM; coluna++)
	{
		printf("%f\n", vetor[coluna]);
	}

}
