#include "stdio.h"
#include "math.h"

/*Função que calcula a distância entre dois vetores*/

/*Antes de tudo, será calculada a diferença entre esses vetores (vetorB - vetorA),
que resultará num vetorC. Desse vetorC, serão calculadas as normas um, dois e infinito,
O que significa que estará sendo calculada a distância entre A e B usando essas normas.
*/


void distanciaVetores(int DIM, float vetorA[],float vetorB[])
{

	int i;
	float vetorC[DIM];

	float normaUm = 0;
	float normaDois = 0;
	float normaInfinito = 0;

	int max = 0;

    /*Cálculo da diferença entre A e B*/
	for (i = 0; i < DIM; i++)
	{
		vetorC[i] = vetorB[i] - vetorA[i];
	}

	/*Calcula da distância(usando normas um, dois e infinito do vetorC)*/


	for (i = 0; i < DIM; ++i)
	{
		/*Norma 1*/
		normaUm = normaUm + sqrt(pow(vetorC[i],2));
		

		/*Norma 2*/
		normaDois = normaDois + pow(vetorC[i],2);
		

		/*Norma no infinito*/
		max = sqrt(pow(vetorC[i],2));
		


        /* se o valor da interação atual é maior do que todos os encontrados anteriormente,
        substitui o maior encontrado anteriormente pelo maior valor atual para a norma
        no infinito*/

		if(max > normaInfinito)
			normaInfinito = max;



	}

	/// término do cálculo a norma 2. Colocar o somatório sob raiz de dois

	normaDois = sqrt(normaDois);


	/*imprimir resultados*/
   
    printf("Distancia calculada usando: \nNorma Um: %f\n", normaUm);
    printf("Norma Dois: %f\n", normaDois);
    printf("Infinito: %f\n",normaInfinito);






}
