#include<iostream>
using namespace std;
void towerOfHanoi(int n, char source, char destination, char auxiliary)
{
     if (n == 0)
        return;
    towerOfHanoi(n - 1, source, auxiliary, destination);
    cout << "Move disk " << n << " from "<< source << " to " << destination << endl;
    towerOfHanoi(n - 1, auxiliary, destination, source);
}
int main()
{
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
    return 0;
}

    
