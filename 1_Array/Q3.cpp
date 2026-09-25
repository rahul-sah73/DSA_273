#include <iostream>
using namespace std;

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;

    while (t--) {
        int n;
        cout << "Enter the number of days: ";
        cin >> n;

        int price[100];
        for (int i = 0; i < n; i++) {
            cin >> price[i];
        }

        int start = 0;
        bool profitFound = false;

        for (int i = 1; i < n; i++) {
            if (price[i] <= price[i - 1]) {
                if (start < i - 1) {
                    cout << "(" << start << " " << i - 1 << ") ";
                    profitFound = true;
                }
                start = i;
            }
        }

        if (start < n - 1) {
            cout << "(" << start << " " << n - 1 << ")";
            profitFound = true;
        }

        if (!profitFound) {
            cout << "No Profit";
        }

        cout << endl;
    }

    return 0;
}
