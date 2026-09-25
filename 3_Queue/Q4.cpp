#include <iostream>
using namespace std;
#define SIZE 100
struct Queue {
    int arr[SIZE];
    int front , rear;
};
void enQueue(Queue* q, int value) {
    if ((q->rear + 1) % SIZE == q->front) {
        return;
    }
    if (q->front == -1) {
        q->front = 0;
        q->rear = 0;
    }
    else {
        q->rear = (q->rear + 1) % SIZE;
    }
    q->arr[q->rear] = value;
}
int deQueue(Queue* q) {
    if (q->front == -1) {
        return -1;
    }
    int value = q->arr[q->front];
    if (q->front == q->rear) {

        q->front = -1;
        q->rear = -1;
    }
    else {

        q->front = (q->front + 1) % SIZE;
    }
    return value;
}

void displayQueue(Queue* q) {
    if (q->front == -1) {
        return;
    }
    int i = q->front;
    while (true) {
        cout << q->arr[i] << " ";
        if (i == q->rear) {
            break;
        }
        i = (i + 1) % SIZE;
    }
    cout << endl;
}
int main() {
    Queue q;
    q.front = -1;
    q.rear = -1;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        enQueue(&q, x);
    }
    displayQueue(&q);
    deQueue(&q);
    displayQueue(&q);
    cout << "CH.SC.U4CSE25273" << endl;
    return 0;
}