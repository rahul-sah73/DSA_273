#include <iostream>
#include <queue>
using namespace std;
int main() {
    int n;
    cin >> n;
    // Min-heap containing the 3 largest elements
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
        // Keep only the 3 largest elements
        if (q.size() > 3) {
            q.pop();
        }
        // Less than 3 elements
        if (q.size() < 3) {
            cout << -1 << endl;
        }
        else {
            // Copy queue so original queue is not changed
            priority_queue<int, vector<int>, greater<int>> temp = q;
            long long product = 1;
            while (!temp.empty()) {

                product = product * temp.top();
                temp.pop();
            }
            cout << product << endl;
        }
    }
    cout << "CH.SC.U4CSE25273" << endl;
    return 0;
}