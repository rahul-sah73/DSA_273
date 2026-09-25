#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

void sortedInsert(struct Node** head_ref, struct Node* new_node) {
    struct Node* current = *head_ref;
    
    if (current == NULL) {
        new_node->next = new_node;
        *head_ref = new_node;
    }
    else if (current->data >= new_node->data) {
        while (current->next != *head_ref)
            current = current->next;
        current->next = new_node;
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else {
        while (current->next != *head_ref && current->next->data < new_node->data)
            current = current->next;
        new_node->next = current->next;
        current->next = new_node;
    }
}

int main() {
    int N;
    if (!(cin >> N)) return 0;
    
    struct Node* head = NULL;
    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        struct Node* new_node = new Node();
        new_node->data = val;
        sortedInsert(&head, new_node);
    }
    
    if (head != NULL) {
        struct Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
    
    return 0;
}
