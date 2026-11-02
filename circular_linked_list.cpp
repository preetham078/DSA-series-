#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node* next;

    Node(string n) {
        name = n;
        next = nullptr;
    }
};

Node* head = nullptr;
Node* tail = nullptr;
Node* currentDriver = nullptr;

void addMember(string name) {
    Node* newNode = new Node(name);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        newNode->next = head;
        currentDriver = head;
    }
    else {
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
    }

    cout << "Member added successfully." << endl;
}

void removeMember(string name) {
    if (head == nullptr) {
        cout << "Member not found." << endl;
        return;
    }

    Node* temp = head;
    Node* prev = tail;

    do {
        if (temp->name == name) {

            if (head == tail) {
                delete temp;
                head = nullptr;
                tail = nullptr;
                currentDriver = nullptr;
            }
            else {
                prev->next = temp->next;

                if (temp == head) {
                    head = temp->next;
                    tail->next = head;
                }

                if (temp == tail) {
                    tail = prev;
                }

                if (temp == currentDriver) {
                    currentDriver = temp->next;
                }

                delete temp;
            }

            cout << "Member removed successfully." << endl;
            return;
        }

        prev = temp;
        temp = temp->next;

    } while (temp != head);

    cout << "Member not found." << endl;
}

void searchMember(string name) {
    if (head == nullptr) {
        cout << "Member not found." << endl;
        return;
    }

    Node* temp = head;
    int position = 1;

    do {
        if (temp->name == name) {
            cout << "Member found at position: "
                 << position << endl;
            return;
        }

        temp = temp->next;
        position++;

    } while (temp != head);

    cout << "Member not found." << endl;
}

void displayRotation() {
    if (head == nullptr) {
        cout << "Driving rotation is empty." << endl;
        return;
    }

    cout << "Current Rotation" << endl;

    Node* temp = head;

    do {
        cout << temp->name << endl;
        temp = temp->next;
    } while (temp != head);

    cout << "(Back to First Member)" << endl;
}

void nextDriver() {
    if (currentDriver == nullptr) {
        cout << "Driving rotation is empty." << endl;
        return;
    }

    cout << "Current driver: "
         << currentDriver->name << endl;

    currentDriver = currentDriver->next;
}

int main() {
    int choice;

    while (cin >> choice) {

        if (choice == 1) {
            string name;
            cin >> name;
            addMember(name);
        }

        else if (choice == 2) {
            string name;
            cin >> name;
            removeMember(name);
        }

        else if (choice == 3) {
            string name;
            cin >> name;
            searchMember(name);
        }

        else if (choice == 4) {
            displayRotation();
        }

        else if (choice == 5) {
            nextDriver();
        }

        else if (choice == 6) {
            cout << "Program exited." << endl;
            break;
        }
    }

    return 0;
}