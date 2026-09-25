#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
void enqueue(int data, int l) {
    q.push(data);
}
void reverse() {
    if (q.empty()) {
        return;
    }
    int x = q.front();
    q.pop();
    reverse();
    q.push(x);
}
void display() {
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        enqueue(x, n);
    }
    cout << "Queue:";
    display();
    reverse();
    cout << "Reversed Queue:";
    display();
    cout << "CH.SC.U4CSE25273" << endl;
    return 0;
}