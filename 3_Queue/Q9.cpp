#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
void enqueue(int d) {
    q.push(d);
}
void dequeue() {
    if (!q.empty()) {
        q.pop();
    }
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
        enqueue(x);
    }
    display();
    dequeue();
    display();
    dequeue();
    display();
    cout << "CH.SC.U4CSE25273" << endl;
    return 0;
}