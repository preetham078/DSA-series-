#include <iostream>
#include <string>
using namespace std;

const int MAX = 5;
string preetham[MAX];
int top = -1;

bool isFull()
{
    return top == MAX - 1;
}

bool isEmpty()
{
    return top == -1;
}

void visitPage()
{
    if (isFull())
    {
        cout << "History stack is full! Overflow.\n";
        return;
    }

    string page;
    cout << "Enter page name: ";
    cin >> page;

    top++;
    preetham[top] = page;

    cout << "Visited page: " << page << endl;
}

void goBack()
{
    if (isEmpty())
    {
        cout << "History stack is empty! Underflow.\n";
        return;
    }

    cout << "Going back from: " << preetham[top] << endl;
    top--;

    if (!isEmpty())
    {
        cout << "Current page: " << preetham[top] << endl;
    }
    else
    {
        cout << "No previous page available.\n";
    }
}

void showCurrentPage()
{
    if (isEmpty())
    {
        cout << "History stack is empty.\n";
        return;
    }

    cout << "Current page: " << preetham[top] << endl;
}

void displayHistory()
{
    if (isEmpty())
    {
        cout << "History stack is empty.\n";
        return;
    }

    cout << "\nBrowser History:\n";

    for (int i = top; i >= 0; i--)
    {
        cout << preetham[i] << endl;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== Browser History =====\n";
        cout << "1. Visit New Page\n";
        cout << "2. Go Back\n";
        cout << "3. Show Current Page\n";
        cout << "4. Display Full History\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            visitPage();
            break;

        case 2:
            goBack();
            break;

        case 3:
            showCurrentPage();
            break;

        case 4:
            displayHistory();
            break;

        case 5:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}