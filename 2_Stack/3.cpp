#include <iostream>
using namespace std;

int digitSum(long long x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}
int main() {
   int n, q;
    cin >> n >> q;
    long long arr[n];
    int arr2[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr2[i] = digitSum(arr[i]);
    }
    while (q--) {
        int i;
        cin >> i;
        i--;
        int answer = -1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {

                if (arr2[i] > arr2[j]) {
                    answer = j + 1;
                    break;
                }
            }
        }
        cout << answer << " ";
    }
    cout << endl << "CH.SC.U4CSE25273" << endl;

    return 0;
}