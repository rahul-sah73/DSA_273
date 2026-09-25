#include <iostream>
#include <stack>
using namespace std;
int main() {
    int n;
    cin >> n;
    long long arr[1000000];
    long long st[1000000];
    int nextGreater[1000000];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    stack<int> s;
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() &&
               arr[s.top()] <= arr[i]) {
            s.pop();
        }
        if (s.empty())
            nextGreater[i] = -1;
        else
            nextGreater[i] = s.top();

        s.push(i);
    }
    long long answer = 0;
    for (int i = n - 1; i >= 0; i--) {
        int j = nextGreater[i];
        if (j == -1)
            st[i] = arr[i];
        else
            st[i] = arr[i] ^ st[j];

        if (st[i] > answer)
            answer = st[i];
    }
    cout << answer;
    cout << endl <<"CH.SC.U4CSE25273" << endl;
    return 0;
}