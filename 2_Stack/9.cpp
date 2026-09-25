#include <iostream>
#include <queue>
using namespace std;
class Stack {
    queue<int> q;

public:
    void push(int val) {
        int size = q.size();
        q.push(val);
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() {
        if (!q.empty()) {
            q.pop();
        }
    }
    int top() {
        if (q.empty())
            return -1;

        return q.front();
    }
};
int main() {
    int n, m;
    cin >> n >> m;
    Stack s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        s.push(x);
    }
    cout << "top of element " << s.top() << endl;
    for (int i = 0; i < m; i++) {
        s.pop();
    }
    cout << "top of element " << s.top();
    cout << endl << "CH.SC.U4CSE25273" << endl;
    return 0;
}