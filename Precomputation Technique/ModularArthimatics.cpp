#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

ll binpow(int a, int b, int m) {
    ll result = 1;  // Changed int to ll to avoid overflow
    while (b > 0) {
        if (b & 1) {
            result = (result * 1ll * a) % m;
        }
        a = (a * 1ll * a) % m;
        b >>= 1;  // Corrected bitwise right shift
    }
    return result;
}

int modularAddition(int a, int b, int m) {
    return (a % m + b % m) % m;
}

int modularSubtraction(int a, int b, int m) {
    return ((a % m - b % m) + m) % m;  // Added m to handle negative results
}

int modularMultiplication(int a, int b, int m) {
    return (a % m * 1ll * b % m) % m;
}

int modularDivision(int a, int b, int m) {
    return (a % m * 1ll * binpow(b, m - 2, m) % m) % m;  // Fixed division logic
}

int main() {
    int a, b;
    cout << "Enter value of a and b: " << endl;
    cin >> a >> b;
    cout << "Enter value of modulo: " << endl;
    int m;
    cin >> m;

    cout << "Modular Addition: " << modularAddition(a, b, m) << endl;
    cout << "Modular Subtraction: " << modularSubtraction(a, b, m) << endl;
    cout << "Modular Multiplication: " << modularMultiplication(a, b, m) << endl;
    cout << "Modular Division: " << modularDivision(a, b, m) << endl;

    return 0;
}
