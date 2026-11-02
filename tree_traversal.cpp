#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int x) : data(x), left(NULL), right(NULL) {}
};

Node* create() {

    int x;
    cin >> x;

    if (x == -1)
        return NULL;

    Node* r = new Node(x);

    r->left = create();
    r->right = create();

    return r;
}

void inorder(Node* r) {

    if (!r)
        return;

    inorder(r->left);

    cout << r->data << " ";

    inorder(r->right);
}

void preorder(Node* r) {

    if (!r)
        return;

    cout << r->data << " ";

    preorder(r->left);
    preorder(r->right);
}

void postorder(Node* r) {

    if (!r)
        return;

    postorder(r->left);
    postorder(r->right);

    cout << r->data << " ";
}

int main() {

    int choice;

    cout << "1. Create tree\n2. Exit\nChoice: ";
    cin >> choice;

    Node* root = NULL;

    if (choice == 1) {

        cout << "Enter nodes in preorder (-1 for no child): ";

        root = create();
    }

    cout << "Inorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    cout << endl;
}