/************************************************
*               TRABALHO ICC                    *
*                                               *
*   Grupo: Pedro Henrique Oliveira Sousa        *
*          Érica Carneiro Araújo                *
*          Ricardo de Carvalho Oliveira Filho   *
*                                               *
//***********************************************/


//Arquivo da biblioteca para a parte de matrizes
#ifndef MATRIZ_H
#define MATRIZ_H

#define ERRO_MAT "\nOpção inválida, digite novamente.\n"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>//biblioteca pra checar se o arquivo existe
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef struct{//struct com todas as informações da matriz
   double linha, coluna;//armazenam o tamanho da linha e da coluna, respectivamente.
   double **mat;//ponteiro que cria a matriz
   char *palavra;//ponteiro para indicar qual matriz o usuário está digitando ou lendo
} matriz;

//Todas as funções da matriz.c
double **cria_matriz(int n,int m);
void ler_matriz(int x, int k);
void imprime_matriz(int x, int k);
void soma_matriz(int q,int w);
void subtrai_matriz(int q,int w);
void multiplica_matriz();
void determinante_matriz();
void matriz_transposta();
void matriz_simetrica();
void inicio_matriz();
void limpa_matriz();
void salvar_matriz();
void tamsave_matriz();
void tamler_matriz();
void importar_matriz();
void matrizes_salvas(int x,int k);
void importa_arquivo_matriz(char *arquivo,int tam);
void salva_arquivo_matriz(char *arquivo,int tam);

#endif
