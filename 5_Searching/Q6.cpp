#include <iostream>
#include <algorithm>

using namespace std;

void thirdLargest(int arr[],int arr_size) {
    if (arr_size < 3) return;
    sort(arr, arr + arr_size, greater<int>());
    cout << "The third Largest element is " << arr[2] << "\n";
}

int main() {
    int N;
    if (cin >> N) {
        int arr[1005];
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        thirdLargest(arr, N);
    }
    return 0;
}
