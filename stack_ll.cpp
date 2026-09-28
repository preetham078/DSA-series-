#include<iostream>
using namespace std;
struct Node {
    int electronic_kit_id;
    Node* next;
    
};
Node* top=NULL;
void push() 
{
    int id;
    cout << "Enter electronic kit ID to push: ";
    cin >> id;
    Node* newNode = new Node();
    newNode->electronic_kit_id = id;
    newNode->next = top;
    top = newNode;
    cout << "Pushed electronic kit ID: " << id << endl;

}
void pop()
{
    if(top==NULL)
    {
        cout<<"underflow"<<endl;
        return; 

    }
    else
    {
        Node* temp=top;
        cout<<"popped electronic kit id: "<<temp->electronic_kit_id<<endl;
        top=top->next;
        delete temp;

    }

}
int main() 
{
    int choice;
    do {
        cout << "\nElectronic Kit Stack\n";
        cout << "1. Push Electronic Kit ID\n";
        cout << "2. Pop Electronic Kit ID\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                cout << "Exiting program\n";
                break;
            default:
                cout << "Invalid choice! .\n";
        }
    } while (choice != 3);

    return 0;
}
