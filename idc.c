#include "stdio.h"
#include "math.h"

/*Função que calcula a Inversa da Transformada Discreta do Cosseno (IDCT)*/
/*Volta para os valores de vetores que estavam antes do conjunto de vetores passar
pela DCT  */

/*Obs: vetorIDCT é vetor da Inversa Da Transformada*/

/*obs: M_PI chama o valor de PI de math.h*/

void IDCT(int DIM, float vetorTransformadaTemporario[], float vetorIDCT[])
{
    int i = 0 , j = 0;

    float aux; // para guardar os cálculos para cada interação


    for(j = 0; j < DIM; j++)
    {

  	    vetorIDCT[j] = 0;

            for(i = 0; i < DIM; i++)
            {
    	      	if(i == 0)
    	      		aux = sqrt(1.0/DIM) * vetorTransformadaTemporario[i] * cos(i);

    	      	if(i >= 1)
    	            aux = sqrt(2.0/DIM) * vetorTransformadaTemporario[i] * cos(i*(2*j + 1)*M_PI/(2.0*DIM));


    	        vetorIDCT[j] = vetorIDCT[j] + aux;

            }

    }



}

/*void IDCT(int DIM, float vetorTransformadaTemporario[], float vetorIDCT[])
{
    int k,n;
    float alfa;

    for (n = 0; n < DIM; n++)
    {
        vetorIDCT[n] = 0;

        for (k = 0; k < DIM; k++)
        {
            if(k == 0)
                alfa = sqrt((1.0/DIM));

            else
                alfa = sqrt((2.0/DIM));


            vetorIDCT[n] =  vetorIDCT[n] + alfa * vetorTransformadaTemporario[k] * cos((M_PI*(2*n + 1)*k)/(2*DIM));
                
        }
    }


}*/
