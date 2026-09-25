#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

void insertStart(struct Node** head, int data) {
    struct Node* newNode = new Node();
    newNode->data = data;
    newNode->next = (*head);
    newNode->prev = NULL;
    if ((*head) != NULL)
        (*head)->prev = newNode;
    (*head) = newNode;
}

int main() {
    int N;
    if (!(cin >> N)) return 0;
    
    struct Node* head = NULL;
    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        insertStart(&head, val);
    }
    
    struct Node* temp = head;
    struct Node* last = NULL;
    while (temp != NULL) {
        cout << temp->data << " ";
        last = temp;
        temp = temp->next;
    }
    cout << endl;
    
    while (last != NULL) {
        cout << last->data << " ";
        last = last->prev;
    }
    cout << endl;
    
    return 0;
}
