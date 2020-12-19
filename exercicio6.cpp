#include <iostream>

using namespace std;

int main() {
    int a, b, c;

    cin >> a >> b >> c;

    if (a <= b && a <= c && b <= c) {
        cout << a << " " << b << " " << c << endl;
    } else if (a <= b && a <= c && c <= b) {
        cout << a << " " << c << " " << b << endl;
    } else if (b <= a && b <= c && a <= c) {
        cout << b << " " << a << " " << c << endl;
    } else if (b <= a && b <= c && c <= a) {
        cout << b << " " << c << " " << a << endl;
    } else if (c <= a && c <= b && b <= a) {
        cout << c << " " << b << " " << a << endl;
    } else if (c <= a && c <= b && a <= b) {
        cout << c << " " << a << " " << b << endl;
    }

    return 0;
}