#include "stdio.h"
#include "math.h"

/*Função que calcula as normas 1 , 2 e infinito do vetor dado pelo usuario(vetorOrigem)
e do vetor encontrado pela TDC(vetorComprido) */

/*Para fazer isso para cada vetor de conjuntoVetores (vetores dados pelo usuario) e 
matrizDaTransformada (vetores gerados pela TDC), essa função está dentro de um loop*/

//obs: sqrt(pow(numero, expoente)) serve para encontrar o módulo.

/*A variavel indiceVetor dirá de qual os vetores(do conjunto de vetores ou da matriz
da transformada) estão sendo calculadas as normas*/

void normasVetores(int DIM, float vetorOrigem[], float vetorComprimido[], int indiceVetor)
{

    int i;
	float normaUmOrigem = 0, normaUmComprimido = 0;
	float normaDoisOrigem = 0, normaDoisComprimido = 0;
	float normaInfinitoOrigem = 0, normaInfinitoComprimido = 0;

	int maxOrigem = 0, maxComprimido = 0;


	/*Calcular as normas 1 2 e infinito do vetor de origem e do comprimido 
	no mesmo loop */


	for (i = 0; i < DIM; ++i)
	{
		/*Norma 1*/
		normaUmOrigem = normaUmOrigem + sqrt(pow(vetorOrigem[i],2));
		normaUmComprimido = normaUmComprimido + sqrt(pow(vetorComprimido[i],2));

		/*Norma 2*/
		normaDoisOrigem = normaDoisOrigem + pow(vetorOrigem[i],2);
		normaDoisComprimido = normaDoisComprimido + pow(vetorComprimido[i],2);


		/*Norma no infinito*/
		maxOrigem = sqrt(pow(vetorOrigem[i],2));
		maxComprimido  = sqrt(pow(vetorComprimido[i],2));


        /* se o valor da interação atual é maior do que todos os encontrados anteriormente,
        substitui o maior encontrado anteriormente pelo maior valor atual para a norma
        no infinito*/

         // para o vetor dado pelo usuário
		if(maxOrigem > normaInfinitoOrigem)
			normaInfinitoOrigem = maxOrigem;


        //para o vetor encontrado na TDC
		if(maxComprimido > normaInfinitoComprimido)
			normaInfinitoComprimido = maxComprimido;



	}

	/// terminar de calcular a norma 2. Colocar o somatório sob raiz de dois

	normaDoisOrigem = sqrt(normaDoisOrigem);
	normaDoisComprimido = sqrt(normaDoisComprimido);


    printf("\nNormas do vetor %d dado pelo usuario:\n", indiceVetor);
   
    printf("Norma Um: %f\n", normaUmOrigem);
    printf("Norma Dois: %f\n", normaDoisOrigem);
    printf("Infinito: %f\n",normaInfinitoOrigem);


    printf("\nNormas do vetor %d encontrado na TDC:\n", indiceVetor);
   
    printf("Norma Um: %f\n", normaUmComprimido);
    printf("Norma Dois: %f\n", normaDoisComprimido);
    printf("Infinito: %f\n",normaInfinitoComprimido);





}
