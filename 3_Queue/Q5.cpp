#include <iostream>
using namespace std;
#define SIZE 100
int q[SIZE];
int front = -1;
int rear = -1;
void enqueue(int data) {
    if (rear == SIZE - 1) {
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    q[rear] = data;
}
void display() {
    if (front == -1) {
        return;
    }
    for (int i = front; i <= rear; i++) {
        cout << q[i] << " ";
    }
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cout << "Enqueuing " << x << endl;
        enqueue(x);
        display();

    }
    cout << endl;
    cout << "CH.SC.U4CSE25273" << endl;
    return 0;
}