#include <iostream>
#include <stack>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    stack<int> A, B;
    for (int i = n - 1; i >= 0; i--) {
        A.push(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        B.push(arr[i]);
    }

    while (!A.empty() && !B.empty()) {

        int a = A.top();
        int b = B.top();

        if (a > b) {
            cout << "1 ";
            B.pop();
        }
        else if (a < b) {
            cout << "2 ";
            A.pop();
        }
        else {
            cout << "0 ";
            A.pop();
            B.pop();
        }
    }
    cout << endl <<"CH.SC.U4CSE25273" << endl;
    return 0;
}