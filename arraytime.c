#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "arraytime.h"
    
int arraytime(float tempovetor[1001]){ //função para armazenar valores em vetor tempo
    FILE *time; //criando ponteiro
    int i=0; //criando variável de contador
    time = fopen("time.txt", "r"); //abrindo e lendo no arquivo
    if(time==NULL){ //condição para existencia do arquivo
        printf("Arquivo não encontrado\n"); //printf para arquivo nao encontrado
        exit(0); //comando de saida da condição
    }
    char g; //crinado variavel char
    fscanf(time, "%f", &tempovetor[i]); //leitura de toda a linha e armazenamento em tempovetor
    g = fgetc(time); //leitura de um caracter apos o outro
    i++; //adicionando 1 ao contador

    while(g != EOF){ //estrutura de repetição enquanto o char nao atingir o fim do arquivo
        if(g == '\n'){ //o ponteiro pulará para o próximo caracter após encontrar \n
            fscanf(time, "%f", &tempovetor[i]); //ler a linha em forma de float
            i++; //adicionar 1 ao contador
        }
    g = fgetc(time); //lendo os caracteres de um a um
    } 
    g = fgetc(time); //novamente a leitura de cada caracter enquanto são printados

    fclose(time); //fechando o arquivo
    return 0;
}