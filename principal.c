#include <stdio.h>

/*Chamadas de funções de outros arquivos*/

extern void TDC(int DIM, float vetorP[], float vetorDatranformada[]);
extern void ImprimirMatriz(int DIM,float matriz[][DIM]);
extern void IDCT(int DIM, float vetorDatranformada[], float vetorIDCT[]);
extern void normasVetores(int DIM, float vetorOrigem[], float vetorComprimido[], int indiceVetor);
extern void distanciaVetores(int DIM, float vetorA[],float vetorB[]);
extern void angulo(int DIM, float vetorX[], float vetorY[]);
extern void normasMatriz(int DIM, float matriz[][DIM]);
extern void distanciaMatrizes(int DIM, float matrizOriginal[][DIM], float matrizComprimida[][DIM]);

int main()
{
	int DIM; // dimensão dos vetores. Equivale ao (p) do enunciado da questão
	int indiceVetor; // Como temos um conj. de vetores, cada vetor terá um índice
	int posicaoNoVetor; // cada vetor, tem suas posições, como já de costume

	int indiceA, indiceB;//guardam os indices dos vetores dos quais serao calculados a distancia
    int indiceX, indiceY; //guardam os indices dos vetores dos quais serao calculados o produto interno e o angulo

	printf("Digite o numero (p) de vetores de dimensao (p) desejado: \n");
	printf("Lembrando que os vetores serao alocados horizontalmente!!!!\n");
	scanf("%d",&DIM);

	printf("Digite as posicoes dos dois vetores dos quais serão calculados a distancia entre si\n");
	printf("Serao calculadas as distancias entre esses vetores antes e depois da TDC\n");
	printf("(digite valores entre 0 e %d)\n",DIM-1);
	scanf("%d",&indiceA);
	scanf("%d",&indiceB);

	printf("Digite as posicoes dos dois vetores dos quais serão \ncalculados produto interno e o angulo entre si\n");
	printf("Serao calculadas o prod. interno e o angulo entre esses vetores antes e depois da TDC\n");
    scanf("%d",&indiceX);
	scanf("%d",&indiceY);


	/*conjuntoVetores é uma "matriz" na qual conjuntoVetores[indiceVetor][posicaoNoVetor] */

	float conjuntoVetores[DIM][DIM]; 
	float matrizDaTransformada[DIM][DIM];

	/*matriz e vetor IDCT é a matriz e o vetor daa inversa da transformada*/

    float matrizIDCT[DIM][DIM];
	float vetorIDCT[DIM];

	// vetor temporario que armazena cada vetor de conjuntoVetores por vez no loop
	float vetorPtemporario[DIM]; 

    //vetor temporario que armazena cada vetor que será de matrizDaTransformada por vez no loop
	float vetorTransformadaTemporario[DIM];

	/*Preencher todos os vetores*/

	for (indiceVetor = 0; indiceVetor < DIM; indiceVetor++)
	{
		for (posicaoNoVetor = 0; posicaoNoVetor < DIM; posicaoNoVetor++)
		{
			printf("Digite a posição %d do vetor %d\n",posicaoNoVetor, indiceVetor);
			scanf("%f",&conjuntoVetores[indiceVetor][posicaoNoVetor]);
		}

	}

	/*Cálculo da Transformada Discreta do Cosseno (TDC)*/
	/*Cálculo da Inversa da transformada do Cosseno (IDCT)*/
	/*Calculo das normas dos vetores dados pelo usuario e os da TDC*/

	for (indiceVetor = 0; indiceVetor < DIM; indiceVetor++)
	{
		/*passar conjuntoValores para vetorPtemporario para entrar na função 
		cada vetor individualmente*/
		for (posicaoNoVetor = 0; posicaoNoVetor < DIM; posicaoNoVetor++)
		{
			vetorPtemporario[posicaoNoVetor] = conjuntoVetores[indiceVetor][posicaoNoVetor]; 
	
		}


		/*Aplicação da TDC*/

		TDC(DIM, vetorPtemporario,vetorTransformadaTemporario);

		/*Cálculo das normas um, dois e infinito dos vetores
		do conjunto de valores e dos encontrados pela TDC*/
		normasVetores(DIM, vetorPtemporario,vetorTransformadaTemporario, indiceVetor);


		/*Aplicação da IDCT*/

		IDCT(DIM,vetorTransformadaTemporario,vetorIDCT);

		/*passar vetorTransformadaTemporario para matrizDaTransformada porque saiu 
		da função cada vetor individualmente*/
		/*passar cada vetorIDCT para a matriz IDCT*/

		for (posicaoNoVetor = 0; posicaoNoVetor < DIM; posicaoNoVetor++)
		{
			matrizDaTransformada[indiceVetor][posicaoNoVetor] = vetorTransformadaTemporario[posicaoNoVetor];
			matrizIDCT[indiceVetor][posicaoNoVetor] = vetorIDCT[posicaoNoVetor];
		}
		
	}

	printf("\nConjunto de vetores:\n");
	ImprimirMatriz(DIM, conjuntoVetores);


	printf("\nMatriz da Transformada:\n");
	ImprimirMatriz(DIM, matrizDaTransformada);

	printf("\nMatriz da Inversa da Transformada:\n");
	ImprimirMatriz(DIM, matrizIDCT);



	/*Calculo da distancia*/
	float vetorA[DIM]; //vetores que receberão os vetores escolhidos pelo usuario para o calculo da distancia
	float vetorB[DIM];

	//Entre os vetores digitados pelo usuario

    for (posicaoNoVetor = 0; posicaoNoVetor < DIM; posicaoNoVetor++)
    { 	
    	vetorA[posicaoNoVetor] = conjuntoVetores[indiceA][posicaoNoVetor];
    	vetorB[posicaoNoVetor] = conjuntoVetores[indiceB][posicaoNoVetor];	
    	
    }

    printf("\nDistancia entre os vetores %d e %d dados pelo usuario:\n",indiceA,indiceB);

    distanciaVetores(DIM, vetorA,vetorB);



     //Entre os vetores da matriz da transformada
    for (posicaoNoVetor = 0; posicaoNoVetor < DIM; posicaoNoVetor++)
    {
    	vetorA[posicaoNoVetor] = matrizDaTransformada[indiceA][posicaoNoVetor];
    	vetorB[posicaoNoVetor] = matrizDaTransformada[indiceB][posicaoNoVetor];
    }

    printf("\nDistancia entre os vetores %d e %d depois da TDC:\n",indiceA,indiceB);

    distanciaVetores(DIM, vetorA,vetorB);


    /*Cálculo do produto interno e do angulo*/
    float vetorX[DIM]; //vetores que receberão os vetores escolhidos pelo usuario para o calculo do prod. int. e do angulo
    float vetorY[DIM];

    //Entre os vetores digitados pelo usuario

    for (posicaoNoVetor = 0; posicaoNoVetor < DIM; posicaoNoVetor++)
    { 	
    	vetorX[posicaoNoVetor] = conjuntoVetores[indiceX][posicaoNoVetor];
    	vetorY[posicaoNoVetor] = conjuntoVetores[indiceY][posicaoNoVetor];	
    	
    }

    printf("\nProduto interno e angulo dos vetores %d e %d dados pelo usuario\n",indiceX,indiceY);
    angulo(DIM, vetorX,vetorY);



     //Entre os vetores da matriz da transformada
    for (posicaoNoVetor = 0; posicaoNoVetor < DIM; posicaoNoVetor++)
    {
    	vetorA[posicaoNoVetor] = matrizDaTransformada[indiceA][posicaoNoVetor];
    	vetorB[posicaoNoVetor] = matrizDaTransformada[indiceB][posicaoNoVetor];
    }
    
    printf("\nProduto interno e angulo dos vetores %d e %d da Transformada\n",indiceX,indiceY);
    angulo(DIM, vetorX,vetorY);

    /*calulo das normas 1, 2 e infinito das matriz dado pelo usuario(conjuntoMatrizes)
    e da comprimida(matrizDaTransformada)*/
    
    printf("\nNormas da matriz dada pelo usuario(conjunto de vetores):\n");
    normasMatriz(DIM, conjuntoVetores);

    printf("\nNormas da matriz oriunda da TDC: \n");
    normasMatriz(DIM, matrizDaTransformada);


    /*Calculo da distancia entre matriz dado pelo usuario(conjuntoMatrizes)
    e a comprimida(matrizDaTransformada)*/

    printf("\nDistancia entre a matriz dada(conjuntoVetores) e a matriz da transformada:\n");
    distanciaMatrizes(DIM, conjuntoVetores, matrizDaTransformada);






    
















	
	return 0;
}
