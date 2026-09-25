#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};

void push(struct node** head_ref, int new_data) {
    struct node* new_node = new node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int GetNth(struct node* head, int index) {
    struct node* current = head;
    int count = 1;
    while (current != NULL) {
        if (count == index)
            return current->data;
        count++;
        current = current->next;
    }
    return -1;
}

int main() {
    int N;
    if (!(cin >> N)) return 0;
    
    struct node* head = NULL;
    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        push(&head, val);
    }
    
    int index;
    cin >> index;
    
    cout << "Linked list:";
    struct node* temp = head;
    while (temp != NULL) {
        cout << "-->" << temp->data;
        temp = temp->next;
    }
    cout << endl;
    
    cout << "Node at index=" << index << ":" << GetNth(head, index) << endl;
    
    return 0;
}
