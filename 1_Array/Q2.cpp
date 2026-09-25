#include <iostream>
using namespace std;

int main() {
    int p, q;
    cout << "Enter rows and columns: ";
    cin >> p >> q;

    char arr[p][q];

    int top = 0, bottom = p - 1;
    int left = 0, right = q - 1;
    char value = 'Y';

    while (top <= bottom && left <= right) {
        // Fill top and bottom rows
        for (int j = left; j <= right; j++) {
            arr[top][j] = value;
            arr[bottom][j] = value;
        }

        // Fill left and right columns
        for (int i = top; i <= bottom; i++) {
            arr[i][left] = value;
            arr[i][right] = value;
        }

        top++;
        bottom--;
        left++;
        right--;

        value = (value == 'Y') ? '0' : 'Y';
    }

    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }

    return 0;
}
