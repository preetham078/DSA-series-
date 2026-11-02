#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

Node *insert(Node *root, int x)
{
    if (root == NULL)
        return new Node(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}

bool search(Node *root, int x)
{
    if (root == NULL)
        return false;

    if (root->data == x)
        return true;

    if (x < root->data)
        return search(root->left, x);

    return search(root->right, x);
}

Node *deleteNode(Node *root, int x)
{
    if (root == NULL)
        return root;

    if (x < root->data)
        root->left = deleteNode(root->left, x);

    else if (x > root->data)
        root->right = deleteNode(root->right, x);

    else
    {
        if (root->left == NULL)
        {
            Node *t = root->right;
            delete root;
            return t;
        }

        if (root->right == NULL)
        {
            Node *t = root->left;
            delete root;
            return t;
        }

        Node *t = root->right;

        while (t->left != NULL)
            t = t->left;

        root->data = t->data;

        root->right =
            deleteNode(root->right, t->data);
    }

    return root;
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);

        cout << root->data << " ";

        inorder(root->right);
    }
}

int main()
{
    Node *root = NULL;

    int a[] = {50, 30, 70, 20, 40, 60, 80};

    for (int x : a)
        root = insert(root, x);

    cout << (search(root, 100) ? "Found" : "Not Found") << endl;

    cout << "Inorder: ";
    inorder(root);

    if (search(root, 90))
    {
        root = deleteNode(root, 90);
        cout << "Deleted";
    }
    else
        cout << "Not Found";

    cout << "\nInorder: ";
    inorder(root);

    root = NULL;

    int b[] = {50, 30, 70, 30, 60};

    for (int x : b)
        root = insert(root, x);

    cout << "Inorder: ";
    inorder(root);

    return 0;
}