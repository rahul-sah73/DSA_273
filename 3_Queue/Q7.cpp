#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

void enqueue(int d) {
    q.push(d);
}

void display() {

    queue<int> temp = q;

    while (!temp.empty()) {
        cout << temp.front() << endl;
        temp.pop();
    }
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

    cout << "CH.SC.U4CSE25273" << endl;

    return 0;
}