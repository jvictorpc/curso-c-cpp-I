#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){

    printf("****************************************************************\n");
    printf("*               jogo da adivinhacao                            *\n");
    printf("****************************************************************\n\n");

    //declaração de variaveis
    int chute, numeroSecreto, maior, acertou, cont;
    double pontos;
   
    int segundos = time(0);
    srand(segundos);
    int num_grande = rand();
    numeroSecreto = num_grande % 100;
    int dificuldade = 0;
    int num_tentativas = 0;

    printf("Informe o nivel de dificuldade:\n");
    printf("(1) Facil (2) Medio (3) Dificil\n");
    scanf("%d", &dificuldade);

    switch(dificuldade){
        case 1:
            num_tentativas = 20;
            break;
        case 2:
            num_tentativas = 15;
            break;
        case 3:
            num_tentativas = 6;
            break;
        default:
            printf("Nao eh uma diculdade valida!!!\n\n");
            break;
    }
    
    cont = 1;
    pontos = 1000;

    for(int i = 1; i<= num_tentativas; i++){

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

    if(acertou){
        printf("vc acertou!!!\n\n");
        printf("===================================================\n");
        printf("FIM DE JOGO\n");
        printf("Voce demorou %d tentativas pra acertar o numero.\n", cont);
        printf("Voce fez %.2f pontos.\n", pontos);
    }else{
        printf("you lose playboy!!! tente denovo.");
    }

   

    system("pause");
    system("cls");    
    return 0;
}