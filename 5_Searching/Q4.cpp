#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int F(int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 16;
        x /= 16;
    }
    return sum;
}

int search(int a, int b) {
    int count = 0;
    for (int x = a; x <= b; x++) {
        if (gcd(x, F(x)) > 1) {
            count++;
        }
    }
    return count;
}

int main() {
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int L, R;
        cin >> L >> R;
        cout << search(L, R) << "\n";
    }
    return 0;
}
