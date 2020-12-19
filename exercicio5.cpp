#include <iostream>

using namespace std;

int main() {
    int N, resultado = 1;

    cin >> N;

    for (int i = N; i >= 1; i--) {
        resultado *= i;
    }

    cout << resultado << endl;

    return 0;
}