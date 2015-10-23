#include "stdio.h"
#include "math.h"

/*Função que calcula a Transformada Discreta do Cosseno(TDC)
Sugiro também olhar a explicação desse método pela internet
*/
//obs: M_PI chama o valor de PI de math.h
                                        
void TDC(int DIM, float vetorPtemporario[], float vetorTransformadaTemporario[])
{
    int i, j;

    float aux; // para guardar os cálculos para cada interação

 
    for(i = 0; i < DIM; i++)
    {

  	    vetorTransformadaTemporario[i] = 0;  // seta zero para não errar no cálculo

	    for(j = 0; j < DIM; j++)
	    {

	      	if(i == 0)
	      	    aux = 1/sqrt(DIM) * vetorPtemporario[j];

	      	if(i >= 1)
	      	  	aux = sqrt(2.0/DIM) * cos(i*M_PI/(2.0*DIM)*(2.0*j + 1)) * vetorPtemporario[j];


	        vetorTransformadaTemporario[i] = vetorTransformadaTemporario[i] + aux;

	       
	    }

    }


}

/*void TDC(int DIM, float vetorPtemporario[], float vetorTransformadaTemporario[])
{
	int n, k; 
	float alfa;

    float somatorio; 

    for (k = 0; k < DIM; k++)
    {
    	somatorio = 0;
    	for (n = 0; n < DIM; n++)
    	{
    		somatorio = somatorio + vetorPtemporario[n] * cos((M_PI*(2*n + 1)*k)/(2*DIM));
    	}

    	if(k == 0)
    		alfa = sqrt((1.0/DIM));

    	else
    		alfa = sqrt((2.0/DIM));

    	vetorTransformadaTemporario[k] = alfa * somatorio;
    }

}*/
