#include <iostream>
#include <stack>
using namespace std;
struct mystack {
    stack<int> s;
};
void push(int data, mystack* ms) {
    ms->s.push(data);
}
int pop(mystack* ms) {
    if (ms->s.empty())
        return -1;
    int x = ms->s.top();
    ms->s.pop();
    return x;
}
void merge(mystack* ms1, mystack* ms2) {
    while (!ms1->s.empty()) {
        cout << pop(ms1) << " ";
    }

    while (!ms2->s.empty()) {
        cout << pop(ms2) << " ";
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    mystack ms1, ms2;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        push(x, &ms1);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        push(x, &ms2);
    }
    merge(&ms1, &ms2);
    cout << endl <<"CH.SC.U4CSE25273" << endl;
    return 0;
}