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

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    for(int i=0;i<n;i++) {
        int val;
        cin >> val;
        create(val);
    }
    
    int D;
    cin >> D;
    
    for(int i=0;i<D;i++) {
        if (head != NULL) {
            node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    cout << "Linked List:";
    node *temp = head;
    while(temp != NULL) {
        cout << "->" << temp->data;
        temp = temp->next;
    }
    cout << endl;
    
    return 0;
}
