#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

node *head = NULL;

void create(int value) {
    node *new_node = new node();
    new_node->data = value;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void del(int D) {
    while (head != NULL && head->data == D) {
        node *temp = head;
        head = head->next;
        delete temp;
    }
    if (head == NULL) return;
    
    node *p2 = head;
    while (p2 != NULL && p2->next != NULL) {
        if (p2->next->data == D) {
            node *temp = p2->next;
            p2->next = temp->next;
            delete temp;
        } else {
            p2 = p2->next;
        }
    }
}

int main() {
    int N;
    if (!(cin >> N)) return 0;
    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        create(val);
    }
    int D;
    cin >> D;
    del(D);
    
    cout << "Linked List:";
    node *temp = head;
    while (temp != NULL) {
        cout << "->" << temp->data;
        temp = temp->next;
    }
    cout << endl;
    
    return 0;
}
