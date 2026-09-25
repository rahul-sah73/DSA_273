#include <iostream>
using namespace std;

int main() {
    int r, c;
    cout << "Enter rows and columns: ";
    cin >> r >> c;

    int arr[20][20];
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }

    int arrTemp[20][20] = {0};

    // Check all cells and replace with 1 if any neighbor is 1.
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] == 1) {
                arrTemp[i][j] = 1;
                // top
                if (i > 0) arrTemp[i - 1][j] = 1;
                // bottom
                if (i + 1 < r) arrTemp[i + 1][j] = 1;
                // left
                if (j > 0) arrTemp[i][j - 1] = 1;
                // right
                if (j + 1 < c) arrTemp[i][j + 1] = 1;
            }
        }
    }

    cout << "Result matrix:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << arrTemp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
