// incluindo as bibliotecas
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

#define QUANTIDADE_DE_PONTOS_INICIAL 1000
#define QUANTIDADE_DE_TENTATIVAS_FACIL 20
#define QUANTIDADE_DE_TENTATIVAS_MEDIO 15
#define QUANTIDADE_DE_TENTATIVAS_DIFICIL 6

int main() {
    bool resposta;

    do {
        // imprimindo cabecalho bonito do jogo
        cout << "\n\n";
        cout << "          P  /_\\  P                              \n";
        cout << "         /_\\_|_|_/_\\                            \n";
        cout << "     n_n | ||. .|| | n_n         Bem vindo ao     \n";
        cout << "     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhacao! \n";
        cout << "    |\" \"  |  |_|  |\"  \" |                     \n";
        cout << "    |_____| ' _ ' |_____|                         \n";
        cout << "          \\__|_|__/                              \n";
        cout << "\n\n";

        // declarando variaveis que serao usadas mais a frente
        int chute;
        bool acertou;
        int nivel;
        int totaldetentativas;

        // definindo a quantidade de pontos inicial
        double pontos = QUANTIDADE_DE_PONTOS_INICIAL;

        // gerando um numero secreto aleatorio
        srand(time(0));
        int numerosecreto;
        int limiteinferior;
        int limitesuperior;

        cout << "Informe o intervalo do numero aleatorio: \n";
        cin >> limiteinferior >> limitesuperior;

        numerosecreto = rand() % (limitesuperior - limiteinferior + 1) + limiteinferior;

        // escolhendo o nivel de dificuldade
        cout << "Qual o nivel de dificuldade?\n";
        cout << "(1) Facil (2) Medio (3) Dificil\n\n";
        cout << "Escolha: ";

        cin >> nivel;

        switch (nivel) {
            case 1:
                totaldetentativas = QUANTIDADE_DE_TENTATIVAS_FACIL;
                break;
            case 2:
                totaldetentativas = QUANTIDADE_DE_TENTATIVAS_MEDIO;
                break;
            default:
                totaldetentativas = QUANTIDADE_DE_TENTATIVAS_DIFICIL;
                break;
        }

        int numerochutado;

        // loop principal do jogo
        for (int i = 1; i <= totaldetentativas; i++) {

            cout << "-> Tentativa " << i << " de " << totaldetentativas << endl;

            cout << "Chute um numero: ";
            cin >> chute;

            if (i == 1) {
                numerochutado = chute;
            } else if (numerochutado == chute) {
                cout << "Voce chutou esse numero anteriormente!\n";
                i--;
                continue;
            } else {
                numerochutado = chute;
            }

            // tratando chute de numero negativo
            if (chute < 0) {
                cout << "Voce não pode chutar numeros negativos!\n";
                i--;
                continue;
            }

            // verifica se acertou, foi maior ou menor
            acertou = chute == numerosecreto;

            if (acertou) {
                break;
            } else if (chute > numerosecreto) {
                cout << "\nSeu chute foi maior do que o numero secreto!\n\n";
            } else {
                cout << "\nSeu chute foi menor do que o numero secreto!\n\n";
            }

            // calcula a quantidade de pontos
            double pontosperdidos = abs(chute - numerosecreto) / 2.0;
            pontos = pontos - pontosperdidos;
        }

        // imprimindo mensagem de vitoria ou derrota
        cout << "\n";
        if (acertou) {
            cout << "             OOOOOOOOOOO               \n";
            cout << "         OOOOOOOOOOOOOOOOOOO           \n";
            cout << "      OOOOOO  OOOOOOOOO  OOOOOO        \n";
            cout << "    OOOOOO      OOOOO      OOOOOO      \n";
            cout << "  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n";
            cout << " OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n";
            cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n";
            cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n";
            cout << "OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n";
            cout << " OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n";
            cout << "  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n";
            cout << "    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n";
            cout << "      OOOOOO   OOOOOOOOO   OOOOOO      \n";
            cout << "         OOOOOO         OOOOOO         \n";
            cout << "             OOOOOOOOOOOO              \n";
            cout << "\nParabens! Voce acertou!\n";
            cout << "Voce fez " << fixed << setprecision(2) << pontos << " pontos.\n\n";
        } else {

            cout << "       \\|/ ____ \\|/    \n";
            cout << "        @~/ ,. \\~@      \n";
            cout << "       /_( \\__/ )_\\    \n";
            cout << "          \\__U_/        \n";

            cout << "\nVoce perdeu! Tente novamente!\n\n";
        }

        cout << "Deseja jogar novamente (1/0) ? ";
        cin >> resposta;
    } while (resposta);

    cout << "Ate a proxima!\n";

    return 0;
}