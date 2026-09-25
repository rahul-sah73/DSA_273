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

        int col;
        cout << "Enter the column number to print: ";
        cin >> col;
        col--;

        cout << "Column " << col + 1 << " elements: ";
        for (int i = 0; i < m; i++) {
            cout << C[i][col] << " ";
        }
        cout << endl;
    }

    return 0;
}
