#include "stdio.h"
#include "math.h"

/*Matriz Original é a dada pelo usuario(conjuntovetor)
e a matriz comprimida é a que veio da TDC (matriz da transformada)*/

/*A distancia entre matrizes é calculada pelo valor máximo(em módulo) da diferença
entre os valores de matrizOriginal e a matrizComprimida.
Em outras palavras, será feita a diferença de cada valor i, j das matrizes
esse valor será posto em módulo. O maior módulo encontrado será a distancia entre as
matrizes.
*/

void distanciaMatrizes(int DIM, float matrizOriginal[][DIM], float matrizComprimida[][DIM])
{

	int linha, coluna;

	float distancia = 0;
	float diferenca = 0; //guarda a diferenca entre cada elemento das matrizes



	for (linha = 0; linha < DIM; linha++)
	{
		for (coluna = 0; coluna < DIM; coluna++)
		{
			diferenca = matrizOriginal[linha][coluna] - matrizComprimida[linha][coluna];
			diferenca = sqrt(pow(diferenca,2));


			if(diferenca > distancia)
				distancia = diferenca;
			
		}
	}

	printf("%f\n",distancia);

}
