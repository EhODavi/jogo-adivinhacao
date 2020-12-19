#include <iostream>

using namespace std;

int main() {
    int a, b, opcao;
    double resultado;

    cin >> a >> b >> opcao;

    switch (opcao) {
        case 1:
            resultado = a + b;
            break;
        case 2:
            resultado = a - b;
            break;
        case 3:
            resultado = a * b;
            break;
        case 4:
            resultado = (double) a / b;
            break;
    }

    cout << resultado;

    return 0;
}