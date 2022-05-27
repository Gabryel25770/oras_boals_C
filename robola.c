//importções necessárias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "arraytime.h"
#include "arrayX.h"

#define velocidade_max 2.8 //definindo a velocidade do robo
#define aceleracao 2.8 //definindo a aceleracao 
#define interc 0.115 //definindo raio de interceptacao

int main(){ //função principal
    int i; //criando variavel contador
    float Xvetor[1001]; //criando vetor x
    float Yvetor[1001]; //criando vetor y 
    float tempovetor[1001]; //criando vetor tempo
    float cosseno[1001]; //criando vetor cosseno
    float seno[1001]; //criando vetor seno
    float robo_velocidade[1001]; //criando vetor da velocidade do robo

    for(i = 0; i < 1002; i++){ //restringindo o contador ao tamanho dos vetores
        robo_velocidade[i] = 0; //igualando valores do robo_velocidade a 0
    }

    float Xrobo_vetor[1001]; //criando vetor do robo em x
    float Yrobo_vetor[1001]; //criando vetor do robo em y


    int v; //criando a variavel v

    arraytime(tempovetor); //chamando função do tempo
    arrayX(Xvetor); //chamando função do x
    arrayY(Yvetor); //chamando função do y


    printf("Modelo do robo: Small Size\n\n"); //printf do modelo do robo
    printf("Digite a posicao inicial do robo em X: "); //pedindo a posição do robo em x
    scanf("%f", &Xrobo_vetor[0]); //scanf do primeiro valor de Xrobo_vetor
    printf("Digite a posicao inicial do robo em Y: "); //pedidno a posição do robo em y
    scanf("%f", &Yrobo_vetor[0]); //scanf do primeiro valor de Yrobo_vetor
    printf("Velocidade da robo: %.3f\n", velocidade_max); //printf da velocidade do robo
    printf("Aceleracao do robo: %.3f\n", aceleracao); //printf da aceleração do robo
    printf("Raio de interceptacao: %.3f metros", interc); //printf do raio de interceptação

    float b_distancia[1001]; //criando vetor de distancia

    for(v = 0; v < 1002; v++){ //restringiu contador v ao tamanho dos vetores
        robo_velocidade[v] = aceleracao*tempovetor[v]; //armazenando os valores de aceleração vezes o tempo no vetor robo_velocidade 

        if(robo_velocidade[v] >= velocidade_max){ //condição para que os valores de robo_velocidade nao ultrapassem 2.8
            robo_velocidade[v] = velocidade_max; //caso isso aconteça ele voltará a ser 2.8
        }
    }

    for(i = 0; i < 1002; i++){ //restringindo o contador ao tamanho dos vetores
        b_distancia[i] = ((Xvetor[i] - Xrobo_vetor[i])*(Xvetor[i] - Xrobo_vetor[i])) + ((Yvetor[i] - Yrobo_vetor[i])*(Yvetor[i] - Yrobo_vetor[i])); //atribuindo valores ao vetor da distancia

        cosseno[i] = (Xvetor[i] - Xrobo_vetor[i]) / sqrt(b_distancia[i]); //achando o cosseno
        seno[i] = (Yvetor[i] - Yrobo_vetor[i]) / sqrt(b_distancia[i]); //achando o seno

        Xrobo_vetor[i+1] = Xrobo_vetor[i] + (cosseno[i] * 0.04); //aumentar o x do robo
        Yrobo_vetor[i+1] = Yrobo_vetor[i] + (seno[i] * 0.05); //aumentar o y do robo

        if(Xrobo_vetor[i] >= Xvetor[i] - interc && Xrobo_vetor[i] <= Xvetor[i] + interc && Yrobo_vetor[i] >= Yvetor[i] - interc && Yrobo_vetor[i] <= Yvetor[i] + interc){ //condições para quando o robo encontrar a bola
            printf("O robo acaba de encontrou a bola!!!\n"); //printf avisando que a bola foi encontrada
            printf("Posicao X do robo: %.3f\n", Xrobo_vetor[i]); //printf da posição do robo em x
            printf("Posicao Y do robo: %.3f\n", Yrobo_vetor[i]); //printf da posição do robo em y
            printf("Velocidade do robo: %.3f\n", robo_velocidade[i]); //printf da velocidade do robo
            printf("Posicao X da bola: %.3f\n", Xvetor[i]); //printf da posição da bola em x
            printf("Posicao Y da bola: %.3f\n", Yvetor[i]); //printf da posição da bola em y
            printf("Tempo: %.3f\n\n", tempovetor[i]); //printf do tempo

            break; //comando para interromper o codigo

        }

        else{ //caso contrario o programa continuará gerando valores
            printf("\n\nPosicao X do robo: %.3f\n", Xrobo_vetor[i]); //printf da posição do robo em x
            printf("Posicao Y do robo: %.3f\n", Yrobo_vetor[i]); //printf da posição do robo em y
            printf("Velocidade do robo: %.3f\n", robo_velocidade[i]); //printf da velocidade do robo
            printf("Posicao X da bola: %.3f\n", Xvetor[i]); //printf da posição da bola em x
            printf("Posicao Y da bola: %.3f\n", Yvetor[i]); //printf da posição da bola em y
            printf("Tempo: %.3f\n\n", tempovetor[i]); //printf do tempo
        }
    }

    system("pause"); //comando para que o programa nao rode em looping eterno
    return 0;
}