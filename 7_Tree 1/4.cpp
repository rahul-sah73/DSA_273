#include <iostream>

using namespace std;

struct node {
    int data;
    struct node *left,*right;
};

struct node* newNode(int item) {
    struct node* temp = new struct node;
    temp->data = item;
    temp->left = temp->right = nullptr;
    return temp;
}

struct node* insert(struct node* node, int data) {
    if (node == nullptr) return newNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    return node;
}

void postorder(struct node* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    struct node* root = nullptr;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        if (i == 0) root = insert(root, val);
        else insert(root, val);
    }
    
    postorder(root);
    cout << endl;
    return 0;
}
