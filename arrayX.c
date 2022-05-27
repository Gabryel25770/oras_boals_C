//importções necessárias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "arrayX.h"

int arrayX(float Xvetor[1001]){ //função para armazenar valores em vetor x
    FILE *xball; //criando ponteiro
    int i=0; //criando variavel contador
    xball = fopen("xball.txt", "r"); //abrindo e lendo o arquivo
    if(xball==NULL){ //condição de existencia do arquivo
        printf("Arquivo não encontrado\n"); //printf para arquivo nao encontrado
        exit(0); //comando de saida da condição
    }
    char g; //criando variavel char
    fscanf(xball, "%f", &Xvetor[i]); //leitura de toda a linha e armazenamento em Xvetor
    g = fgetc(xball); //leitura de um caracter apos o outro
    i++; //adiciona 1 ao contador

    while(g != EOF){ //estrutura de repetição enquanto o char nao atingir o fim do arquivo
        if(g=='\n'){ //o ponteiro pulará para o proximo caracter após encontrar \n
            fscanf(xball, "%f", &Xvetor[i]); //ler a linha em forma de float
            i++; //adicionar 1 ao contador
        }
    g = fgetc(xball); //lendo caracteres um a um
    }
    g = fgetc(xball); //novamente a leitura de cada caracter enquanto são printados



    fclose(xball); //fechando o arquivo
    return 0;
}