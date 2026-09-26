#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << (i == n-1 ? "" : " ");
    cout << endl;
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        if (i == 3) {
            printArray(arr, n);
        }
    }
}

int main() {
    int n;
    if (cin >> n) {
        int arr[100005];
        for(int i=0; i<n; i++) cin >> arr[i];
        insertionSort(arr, n);
        printArray(arr, n);
    }
    return 0;
}
