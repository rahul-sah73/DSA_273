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
    int nextGreater[n];
    int nextSmaller[n];
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() &&
               arr[st.top()] <= arr[i]) {
            st.pop();
        }
        if (st.empty())
            nextGreater[i] = -1;
        else
            nextGreater[i] = st.top();

        st.push(i);
    }
    while (!st.empty())
        st.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() &&
               arr[st.top()] >= arr[i]) {
            st.pop();
        }
        if (st.empty())
            nextSmaller[i] = -1;
        else
            nextSmaller[i] = st.top();

        st.push(i);
    }
    for (int i = 0; i < n; i++) {
        if (nextGreater[i] == -1) {
            cout << -1 << " ";
        }
        else {
            int j = nextGreater[i];
            if (nextSmaller[j] == -1)
                cout << -1 << " ";
            else
                cout << arr[nextSmaller[j]] << " ";
        }
    }
    cout << endl << "CH.SC.U4CSE25273" << endl;

    return 0;
}