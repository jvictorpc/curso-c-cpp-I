#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main (){
    
    //declaração de variaveis
    int chute, numeroSecreto, maior, acertou=0, cont;
    double pontos;
   
   //gerando numeros aleatórios usando o tempo 
    int segundos = time(0);
    srand(segundos);
    int num_grande = rand();
    numeroSecreto = num_grande % 100;
    int dificuldade = 0;
    int ehvalido = 0;
    int num_tentativas = 0;

    //só sai do loop se o valor digitado for válido
    while (ehvalido == 0){  
        printf("\n\n");  
        printf("               ______________________                          \n");
        printf("              |                      |_____    __                    \n");
        printf("              |  JOGO DA ADIVINHACAO |     |__|  |____          \n");
        printf("              |______________________|     |::|  |    /          \n");
        printf(" /\\**/\\       |                \\.____|::|__|      <         \n");
        printf("( o_o  )_     |                      \\::/  \\._______\\       \n");
        printf(" (u--u   \\_)  |                                               \n");
        printf("  (||___   )==\\                                               \n");
        printf(",dP\"/b/=( /P\\\"/b\\                                          \n");
        printf("|8 || 8\\=== || 8                                              \n");
        printf("`b,  ,P  `b,  ,P                                               \n");
        printf("  \"\"\"`     \"\"\"`                                          \n");
        printf("================================================================\n");

        printf("Informe o nivel de dificuldade:\n");
        printf("(1) Facil (2) Medio (3) Dificil (4) Sair\n");
        scanf("%d", &dificuldade);

    
        switch(dificuldade){
            case 1:
                num_tentativas = 20;
                ehvalido = 1;
                break;
            case 2:
                num_tentativas = 15;
                ehvalido = 1;
                break;
            case 3:
                num_tentativas = 6;
                ehvalido = 1;
                break;
            case 4:
                ehvalido = 1;
                system("cls");
                return 0; 
                break;
            default:
                printf("Nao eh uma diculdade valida!!!\n\n");
                system("pause");
                system("cls");
                break;
        }

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
        printf("               _____                                       \n");
        printf("              /     \\           PARABENS!!!               \n");
        printf("              vvvvvvv  /|__/|   VOCE VENCEU!!!             \n");
        printf("                 I   /O,O   |                              \n");
        printf("                 I /_____   |      /|/|                    \n");
        printf("                J|/^ ^ ^ \\  |    /00  |    _//|           \n");
        printf("                 |^ ^ ^ ^ |W|   |/^^\\ |   /oo |           \n");
        printf("                  \\m___m__|_|    \\m_m_|   \\mm_|         \n");

        printf("===================================================\n");
        printf("FIM DE JOGO\n");
        printf("Voce demorou %d tentativas pra acertar o numero.\n", cont);
        printf("Voce fez %.2f pontos.\n", pontos);
    }else{

        printf("       _..._                     \n");
        printf("     .'     '.                      \n");
        printf("    /`\\     /`\\    |\\               \n");
        printf("   (__|     |__)    \\\\              \n");
        printf("   (     \"     )    ||              \n");
        printf("    \\         /    _||_            \n");
        printf("     \\ \\__/  /  |\\|`  /             \n");
        printf("      '.___.'   \\____/              \n");
        printf("       (___)    (___)               \n");
        printf("     /`     `\\  / /                 \n");
        printf("    |         \\/ /                  \n");
        printf("    | |  VC  |\\  /                   \n");
        printf("    | |PERDEU| \"`                    \n");
        printf("    | |OTARIO|                       \n");
        printf("    | | !!!  |                       \n");
    }

   

    system("pause");
    system("cls");    
    return 0;
}