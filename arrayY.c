//importções necessárias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "arrayY.h"

int arrayY(float Yvetor[1001]){ //função para armazenar valores no vetor y
    FILE *yball; //criando ponteiro
    int i=0; //criando variavel de contador
    yball = fopen("yball.txt", "r"); //abrindo e lendo o arquivo
    if(yball == NULL){ //condição de existencia do arquivo
        printf("Arquivo não encontrado\n"); //printf para arquivo nao encontrado
        exit(0); //comando de saida da condição
    }
    char g; //criando variavel char
    fscanf(yball, "%f", &Yvetor[i]); //leitura de toda a linha e armazenamento em Yvetor
    g = fgetc(yball); //leitura de um caracter após o outro
    i++; //adicionando 1 ao contador

    while(g != EOF){ //estrutura de repetição enquanto o char nao atingir o fim do arquivo
        if(g == '\n'){ //o ponteiro pulará para o próximo caracter após encontrar \n
            fscanf(yball, "%f", &Yvetor[i]); //ler linha em forma de float
            i++; //adicionando 1 ao contador
        }
    g = fgetc(yball); //lendo caracteres um a um
    }
    g = fgetc(yball); //lendo novamente cada caracter enquanto são printados


    fclose(yball); //fechando o arquivo
    return 0;
}