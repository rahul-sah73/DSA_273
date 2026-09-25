#include <iostream>
using namespace std;

int main() {
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;

    while (t--) {
        int m, n;
        cout << "Enter rows and columns: ";
        cin >> m >> n;

        int C[20][20];
        cout << "Enter matrix elements:\n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> C[i][j];
            }
        }

        int r1, c1, r2, c2;
        cout << "Enter submatrix range as r1 c1 r2 c2: ";
        cin >> r1 >> c1 >> r2 >> c2;

        // Convert to 0-based indexes.
        r1--;
        c1--;
        r2--;
        c2--;

        int sum = 0;

        // Add all values in the chosen submatrix.
        for (int i = r1; i <= r2; i++) {
            for (int j = c1; j <= c2; j++) {
                sum += C[i][j];
            }
        }

        cout << "Sum of selected submatrix = " << sum << endl;
    }

    return 0;
}
