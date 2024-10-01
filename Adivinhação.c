// incluindo as bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h> // Para definir o idioma

// definindo as constantes
#define NUMERO_DE_TENTATIVAS_FACIL 20
#define NUMERO_DE_TENTATIVAS_MEDIO 15
#define NUMERO_DE_TENTATIVAS_DIFICIL 6
#define PONTOS_INICIAIS 1000

int main() {
    setlocale(LC_ALL, "Portuguese");

    int jogarNovamente;

    do {
        // imprimindo cabe�alho bonito do jogo
        printf("\n\n");
        printf("     _            _        \n");
        printf("    | |          | |       \n");
        printf("  __| |_   _  ___| | _____ \n");
        printf(" / _` | | | |/ __| |/ / __|\n");
        printf("| (_| | |_| | (__|   <\\__ \\\n");
        printf(" \\__,_|\\__,_|\\___|_|\\_\\___/\n");
        printf("                            \n\n");
        printf("************************************\n");
        printf("* Bem vindo ao Jogo de Adivinha��o *\n");
        printf("************************************\n");

        // declarando vari�veis
        int chute;
        int acertou = 0;
        int nivel;
        int totaldetentativas;
        int ultimoChute = -1;  // Vari�vel para armazenar o �ltimo chute
        double pontos = PONTOS_INICIAIS; // definindo a quantidade de pontos inicial

        // Obtendo o limite de n�meros do usu�rio
        int limiteInferior, limiteSuperior;
        printf("Escolha o intervalo para o n�mero secreto.\n");
        printf("Digite o limite inferior: ");
        scanf("%d", &limiteInferior);
        printf("Digite o limite superior: ");
        scanf("%d", &limiteSuperior);

        // Gerando um n�mero secreto aleat�rio dentro do intervalo
        srand(time(0));
        int numerosecreto = rand() % (limiteSuperior - limiteInferior + 1) + limiteInferior;

        // escolhendo o n�vel de dificuldade
        printf("\nQual o n�vel de dificuldade?\n");
        printf("(1) F�cil (2) M�dio (3) Dif�cil\n");
        printf("Escolha: ");
        scanf("%d", &nivel);

        // Definindo o n�mero de tentativas com base no n�vel escolhido
        switch (nivel) {
            case 1:
                totaldetentativas = NUMERO_DE_TENTATIVAS_FACIL;
                break;
            case 2:
                totaldetentativas = NUMERO_DE_TENTATIVAS_MEDIO;
                break;
            default:
                totaldetentativas = NUMERO_DE_TENTATIVAS_DIFICIL;
                break;
        }

        // loop principal do jogo
        int i = 1; // Vari�vel de controle do loop (declara��o fora do `for`)
        for (; i <= totaldetentativas; i++) {
            printf("-> Tentativa %d de %d\n", i, totaldetentativas);
            printf("Chute um n�mero: ");
            scanf("%d", &chute);

            // Verificando se o chute � repetido
            if (chute == ultimoChute) {
                printf("Voc� j� chutou o n�mero %d. Tente outro n�mero!\n", chute);
                i--; // N�o conta como tentativa
                continue;
            }

            // Salvando o chute atual como �ltimo chute
            ultimoChute = chute;

            // tratando chute de n�mero negativo
            if (chute < 0) {
                printf("Voc� n�o pode chutar n�meros negativos.\n");
                i--;
                continue;
            }

            // verifica se acertou, foi maior ou menor
            acertou = chute == numerosecreto;

            if (acertou) {
                break;
            } else if (chute > numerosecreto) {
                printf("\nSeu chute foi maior do que o n�mero secreto!\n\n");
            } else {
                printf("\nSeu chute foi menor do que o n�mero secreto!\n\n");
            }

            // calcula a quantidade de pontos
            double pontosperdidos = abs(chute - numerosecreto) / 2.0;
            pontos -= pontosperdidos;
        }

        // imprimindo mensagem de vit�ria ou derrota
        printf("\n");
        if (acertou) {
            printf("             OOOOOOOOOOO               \n");
            printf("         OOOOOOOOOOOOOOOOOOO           \n");
            printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
            printf("    OOOOOO      OOOOO      OOOOOO      \n");
            printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
            printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
            printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
            printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
            printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
            printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
            printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
            printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
            printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
            printf("         OOOOOO         OOOOOO         \n");
            printf("             OOOOOOOOOOOO              \n");
            printf("\nParab�ns! Voc� acertou!\n");
            printf("Voc� fez %.2f pontos. At� a pr�xima!\n\n", pontos);
        } else {
            printf("       \\|/ ____ \\|/    \n");
            printf("        @~/ ,. \\~@      \n");
            printf("       /_( \\__/ )_\\    \n");
            printf("          \\__U_/        \n");
            printf("\nVoc� perdeu! O n�mero secreto era %d. Tente novamente!\n\n", numerosecreto);
        }

        // Pergunta se o jogador quer jogar novamente
        printf("Deseja jogar novamente? (1 - Sim / 0 - N�o): ");
        scanf("%d", &jogarNovamente);

    } while (jogarNovamente == 1);

    printf("\nObrigado por jogar! At� a pr�xima.\n");

    return 0;
}


