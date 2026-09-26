#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (!(cin >> t)) return 0;
    double phi = (1.0 + sqrt(5.0)) / 2.0;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        long long diff = abs(a - b);
        long long min_val = min(a, b);
        if (min_val == (long long)(diff * phi)) {
            cout << "sami\n";
        } else {
            cout << "canthi\n";
        }
    }
    return 0;
}

