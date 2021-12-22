#include <stdio.h>
#include <stdlib.h>

int main (){

    printf("****************************************************************\n");
    printf("*           Bem vindo ao jogo da adivinhacao                 *\n");
    printf("****************************************************************\n\n");

    //declaração de variaveis
    int chute, numeroSecreto, maior, acertou, cont;
    double pontos;

    numeroSecreto = 42;
    cont = 1;
    pontos = 1000;

    while(1){

        printf("Tentativa numero %d \n\n",cont );

        printf("Informe o seu chute: ");
        scanf("%d", &chute);

        if (chute < 0){
            printf("Numeros negativos nao serao contados!!!\n\n");
            //interrompe o laço for, ma sem quebrar o loop, apenas passa para a proxima iteração
            continue;
        }

        acertou = chute == numeroSecreto;
        maior = chute > numeroSecreto;

        if(acertou){
            printf("vc acertou!!!\n\n");
            break;
        }else if (maior){
            printf("O numero secreto eh menor!!\n\n");
        }else{
            printf("O numero secreto eh maior!!\n\n");
        }

        double pontos_perdidos =(double) abs((chute - numeroSecreto))/2;
        pontos = pontos - pontos_perdidos;
        cont++;
    }
    printf("===================================================\n");
    printf("FIM DE JOGO\n");
    printf("Voce demorou %d tentativas pra acertar o numero.\n", cont);
    printf("Voce fez %.2f pontos", pontos);
        
    return 0;
}