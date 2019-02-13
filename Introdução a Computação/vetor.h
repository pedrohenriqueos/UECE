/************************************************
*               TRABALHO ICC                    *
*                                               *
*   Grupo: Pedro Henrique Oliveira Sousa        *
*          Érica Carneiro Araújo                *
*          Ricardo de Carvalho Oliveira Filho   *
*                                               *
//***********************************************/

#ifndef VET_H
#define VET_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>//biblioteca pra checar se o arquivo existe

// Struct que irá guardar os dados do vetor.

struct vetor
{
    double *pont, *coordenadas;
    double modulo;
    double coor;
    char *palavra;
};

double *recebe_coord(int op);
double cria_modulo(double *vet,int a);
double *cria_vetor(double tam);
void alimenta_struct_vetor();
double *soma_vetor();
double *subtracao_vetor(int sub);
double *produto_escalar();
double produto_de_vetores();
void limpa_vetor();
void inicio_vetor();
void salvar_vetor(char *nome);
void tamsave_vetor(char *nome);
void tamler_vetor(char *nome);
void importar_vetor(char *nome);
void vetores_salvos();
void importar_arquivo_vetor(char *arquivo2,int tam,int iniciov);
void salva_arquivo_vetor(char *arquivo2,int tam);

#endif
