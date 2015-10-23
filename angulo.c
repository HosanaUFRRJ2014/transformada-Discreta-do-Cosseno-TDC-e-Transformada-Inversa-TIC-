#include "stdio.h"
#include "math.h"

/*Função que calcula o produto interno e o ângulo entre dois vetores vetores X e Y*/

void angulo(int DIM, float vetorX[], float vetorY[])
{
	int i;
	float produtoInterno = 0;
	float normaDeX = 0, normaDeY = 0; // armazena as normas de x e Y para o cálculo do ângulo
    float cosseno = 0; //será armazenado o valor do angulo

    /*Calculo do produto interno*/
	for (i = 0; i < DIM; i++)
	{
		produtoInterno = produtoInterno + vetorX[i] * vetorY[i];
	}


	/*****Calculo do angulo*********/

	/*cos(ø) = <x,y>/( ||X|| * ||Y|| )*/
	//será usada a norma dois

	//calculo da norma

	for (i = 0; i < DIM; i++)
	{
		normaDeX = normaDeX + pow(vetorX[i],2);
		normaDeY = normaDeY + pow(vetorX[i],2);
		
	}

	/// terminar de calcular a norma 2. Colocar o somatório sob raiz de dois

	normaDeX = sqrt(normaDeX);
	normaDeY = sqrt(normaDeY);

	cosseno = produtoInterno/(normaDeX * normaDeY);

	/*Usar função da math.h para achar o arco cosseno (em radianos)*/
	cosseno = acos(cosseno);

	/*Convertendo para graus. */

	//cosseno = (cosseno * 180)/M_PI; 


    /*Imprimir o produtoInterno e o angulo etre os vetores*/
	printf("Produto interno: %f\n",produtoInterno);
	printf("Angulo(em radianos): %f\n",cosseno);



}
