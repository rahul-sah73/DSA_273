#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

void insert_Data(struct node **head, int data) {
    node *new_node = new node();
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
    } else {
        node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void delete_Alt(struct node **head) {
    if (*head == NULL) return;
    
    node *a = *head;
    node *b = (*head)->next;
    
    while (a != NULL && b != NULL) {
        a->next = b->next;
        delete b;
        a = a->next;
        if (a != NULL) {
            b = a->next;
        }
    }
}

int main() {
    int N;
    if (!(cin >> N)) return 0;
    
    struct node *head = NULL;
    for (int i = 1; i <= N; i++) {
        insert_Data(&head, i);
    }
    
    delete_Alt(&head);
    
    node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    
    return 0;
}
