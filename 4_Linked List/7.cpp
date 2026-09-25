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

void del(int P) {
    node *temp = head;
    bool found = false;
    while (temp != NULL) {
        if (temp->data == P) {
            found = true;
            break;
        }
        temp = temp->next;
    }
    
    if (found) {
        head = temp; 
        cout << "Linked List:";
        node *p1 = head;
        while (p1 != NULL) {
            cout << "->" << p1->data;
            p1 = p1->next;
        }
        cout << endl;
    } else {
        cout << "Invalid Node! Linked List:";
        node *p1 = head;
        while (p1 != NULL) {
            cout << "->" << p1->data;
            p1 = p1->next;
        }
        cout << endl;
    }
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    for(int i=0;i<n;i++) {
        int val;
        cin >> val;
        create(val);
    }
    
    int P;
    cin >> P;
    
    del(P);
    
    return 0;
}
