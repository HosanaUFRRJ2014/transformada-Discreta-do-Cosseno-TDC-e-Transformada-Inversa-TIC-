# transformada-Discreta-do-Cosseno-TDC-e-Transformada-Inversa-TIC-
Construção de um algoritmo que recebe um vetor p vetores de tamanho p. Aplica-se a Transformada Unidimensional Discreta do Cosseno (DCT) para obter a matriz de compressão. Usa-se a Transformada Inversa para avaliar a qualidade da transformação. Compara-se as normas de cada vetor. Para fazê-lo, calcula-se a norma 1, norma 2 e norma infinito de qualquer vetor x, avaliando a distância entre os dois vetores originais e comprimidos usando a norma 1, 2 e infinito. Além disso, ainda há um algoritmo que calcula o produto interno e o do ângulo entre dois vetores x e y. Constroi-se um algoritmo que calcule a norma 1, norma infinito e norma de Frobenius das duas matrizes envolvidas no problema e calcula-se a distância entre essas matrizes.


READ-ME: Para Compilar(compilador GCC)

gcc imprimirMatriz.c imprimirVetor.c  tdc.c idc.c normasVetores.c distanciaVetores.c angulo.c normasMatriz.c distanciaMatrizes.c principal.c -lm -o principal
