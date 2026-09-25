#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

node *start = NULL;

void display() {
    cout << "Linked List:";
    node *temp = start;
    while (temp != NULL) {
        cout << "->" << temp->data;
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int N;
    if (!(cin >> N)) return 0;
    
    node *tail = NULL;
    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        node *new_node = new node();
        new_node->data = val;
        new_node->next = NULL;
        if (start == NULL) {
            start = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }
    
    int P, X;
    cin >> P >> X;
    
    bool found = false;
    node *p2 = NULL;
    node *temp = start;
    
    while (temp != NULL) {
        if (temp->data == P) {
            found = true;
            break;
        }
        p2 = temp;
        temp = temp->next;
    }
    
    if (found) {
        node *p1 = new node();
        p1->data = X;
        if (p2 == NULL) {
            p1->next = start;
            start = p1;
        } else {
            p1->next = temp;
            p2->next = p1;
        }
    } else {
        cout << "Node not found!" << endl;
    }
    
    display();
    
    return 0;
}
