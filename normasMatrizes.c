#include "stdio.h"
#include "math.h"

/*Função que calcula as as normas 1, infinito e frobenius das matrizes*/
 

void normasMatriz(int DIM, float matriz[][DIM])
{
	int linha, coluna;
	float normaUm = 0, normaInfinito = 0, normaFrobenius = 0;
	float soma = 0; // auxiliar para guardar as somas das normas
    
    /*Norma Um ->  é o máximo do somatório de cada coluna*/
	for (coluna = 0; coluna < DIM; coluna++)
	{
		soma = 0;

		for (linha = 0; linha < DIM; linha++)
		{
			soma = soma + sqrt(pow(matriz[linha][coluna],2));

			
		}

		if(soma > normaUm) // se a soma dessa coluna é maior de todas até o momento
			normaUm = soma;
	}

	/*Norma no infinito -> é o máximo do somatório de cada linha */

	for (linha = 0; linha < DIM; linha++)
	{
		soma = 0;

		for (coluna = 0; coluna < DIM; coluna++)
		{
			soma = soma + sqrt(pow(matriz[linha][coluna],2));
			
		}

		if(soma > normaInfinito) // se a soma dessa linha é maior de todas até o momento
			normaInfinito = soma;


	}

	/*Norma de Frobenius -> somatŕio de todos os elementos² da matriz sob raiz de dois*/

	for (linha = 0; linha < DIM; linha++)
	{
		for (coluna = 0; coluna < DIM; coluna++)
		{
			normaFrobenius = normaFrobenius + pow(matriz[linha][coluna],2);
			
		}
	}

	normaFrobenius = sqrt(normaFrobenius);

	printf("Norma Um: %f\n", normaUm);
	printf("Norma no Infinito: %f\n", normaInfinito);
	printf("Norma de Frobenius: %f\n", normaFrobenius);


}
