#include <iostream>
#include <string>
using namespace std;

struct Node {
    string folder;
    Node* next;
    Node* prev;
};

Node* head = nullptr;
Node* tail = nullptr;
Node* curr = nullptr;

void createNode(string f) {
    Node* newNode = new Node{f, nullptr, nullptr};

    if (head == nullptr) {
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    curr = head;

    cout << "Folder inserted at beginning." << endl;
}

void insertEnd(string f) {
    if (head == nullptr) {
        createNode(f);
        return;
    }

    Node* node = new Node{f, nullptr, tail};

    tail->next = node;
    tail = node;

    cout << "Folder inserted at end." << endl;
}

void insertAt(int p, string f) {
    if (p <= 1 || head == nullptr) {
        createNode(f);
        return;
    }

    Node* temp = head;
    int count = 1;

    while (temp->next != nullptr && count < p - 1) {
        temp = temp->next;
        count++;
    }

    if (temp->next == nullptr) {
        insertEnd(f);
        return;
    }

    Node* node = new Node{f, temp->next, temp};

    temp->next->prev = node;
    temp->next = node;

    cout << "Folder inserted successfully." << endl;
}

void deleteStart() {
    if (head == nullptr)
        return;

    Node* temp = head;

    cout << "Deleted folder: "
         << temp->folder << endl;

    if (head == tail) {
        head = tail = curr = nullptr;
    }
    else {
        head = head->next;
        head->prev = nullptr;

        curr = head;
    }

    delete temp;

    cout << "Folder deleted from beginning." << endl;
}

void deleteEnd() {
    if (tail == nullptr)
        return;

    Node* temp = tail;

    cout << "Deleted folder: "
         << temp->folder << endl;

    if (head == tail) {
        head = tail = curr = nullptr;
    }
    else {
        tail = tail->prev;
        tail->next = nullptr;

        if (curr == temp)
            curr = tail;
    }

    delete temp;

    cout << "Folder deleted from end." << endl;
}

void deleteAt(int p) {
    if (head == nullptr)
        return;

    if (p <= 1) {
        deleteStart();
        return;
    }

    Node* temp = head;

    for (int c = 1; c < p && temp != nullptr; c++) {
        temp = temp->next;
    }

    if (temp == nullptr)
        return;

    cout << "Deleted folder: "
         << temp->folder << endl;

    if (temp == tail) {
        tail = tail->prev;

        if (tail != nullptr) {
            tail->next = nullptr;
        }
        else {
            head = nullptr;
        }
    }
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    if (curr == temp) {
        curr = (temp->prev != nullptr)
             ? temp->prev
             : head;
    }

    delete temp;
}

void moveNext() {
    if (curr != nullptr && curr->next != nullptr) {
        curr = curr->next;

        cout << "Current folder: "
             << curr->folder << endl;
    }
}

void movePrev() {
    if (curr != nullptr && curr->prev != nullptr) {
        curr = curr->prev;

        cout << "Current folder: "
             << curr->folder << endl;
    }
}

void display() {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->folder << endl;
        temp = temp->next;
    }
}

int main() {
    int choice, p;
    string f;

    while (cin >> choice) {

        if (choice == 1) {
            cin >> f;
            createNode(f);
        }

        else if (choice == 2) {
            cin >> f;
            insertEnd(f);
        }

        else if (choice == 3) {
            cin >> p >> f;
            insertAt(p, f);
        }

        else if (choice == 4) {
            deleteStart();
        }

        else if (choice == 5) {
            deleteEnd();
        }

        else if (choice == 6) {
            cin >> p;
            deleteAt(p);
        }

        else if (choice == 8) {
            display();
        }

        else if (choice == 9) {
            movePrev();
        }

        else if (choice == 10) {
            moveNext();
        }
    }

    return 0;
}