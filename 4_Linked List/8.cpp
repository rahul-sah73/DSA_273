#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};

void create(struct node **head, int data) {
    struct node *new_node = new node();
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void print(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    struct node *head = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        create(&head, val);
    }
    
    cout << "Link list data:";
    print(head);
    
    if (head == NULL || head->next == NULL) {
        cout << "Link list data after fold:";
        print(head);
        return 0;
    }
    
    struct node *slow = head;
    struct node *fast = head->next;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    struct node *head1 = head;
    struct node *head2 = slow->next;
    slow->next = NULL;
    
    struct node *prev = NULL;
    struct node *curr = head2;
    struct node *nxt = NULL;
    while (curr != NULL) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    head2 = prev;
    
    struct node *folded_head = new node();
    struct node *tail = folded_head;
    
    struct node *p1 = head1;
    struct node *p2 = head2;
    while (p1 != NULL || p2 != NULL) {
        if (p1 != NULL) {
            tail->next = p1;
            tail = p1;
            p1 = p1->next;
        }
        if (p2 != NULL) {
            tail->next = p2;
            tail = p2;
            p2 = p2->next;
        }
    }
    
    cout << "Link list data after fold:";
    print(folded_head->next);
    
    return 0;
}
