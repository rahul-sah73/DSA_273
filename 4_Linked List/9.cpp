#include <iostream>
using namespace std;

struct n {
    int data;
    struct n *next;
};

struct n *head = NULL;
struct n *tail = NULL;

void insert(int data) {
    struct n *new_node = new n();
    new_node->data = data;
    if (head == NULL) {
        head = new_node;
        new_node->next = head;
        tail = new_node;
    } else {
        tail->next = new_node;
        new_node->next = head;
        tail = new_node;
    }
}

void display(struct n *h) {
    if (h == NULL) return;
    cout << "[h]";
    struct n *temp = h;
    do {
        cout << "=>" << temp->data;
        temp = temp->next;
    } while (temp != h);
    cout << "=>[h]" << endl;
}

int main() {
    int num;
    if (!(cin >> num)) return 0;
    
    for (int i = 1; i <= num; i++) {
        insert(i);
    }
    
    cout << "Complete linked_list:\n";
    display(head);
    
    struct n *odd_head = NULL;
    struct n *odd_tail = NULL;
    struct n *even_head = NULL;
    struct n *even_tail = NULL;
    
    struct n *temp = head;
    int count = 1;
    if (temp != NULL) {
        do {
            struct n *new_node = new n();
            new_node->data = temp->data;
            
            if (count % 2 != 0) {
                if (odd_head == NULL) {
                    odd_head = new_node;
                    new_node->next = odd_head;
                    odd_tail = new_node;
                } else {
                    odd_tail->next = new_node;
                    new_node->next = odd_head;
                    odd_tail = new_node;
                }
            } else {
                if (even_head == NULL) {
                    even_head = new_node;
                    new_node->next = even_head;
                    even_tail = new_node;
                } else {
                    even_tail->next = new_node;
                    new_node->next = even_head;
                    even_tail = new_node;
                }
            }
            
            temp = temp->next;
            count++;
        } while (temp != head);
    }
    
    cout << "Odd:\n";
    display(odd_head);
    
    cout << "Even:\n";
    display(even_head);
    
    return 0;
}
