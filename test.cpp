#include <iostream>
using namespace std;
#include <cmath>

int Count = 0;

int towerOfHanoi(int n, char source, char dest, char aux)
{
    if (n == 0)
        return 0;

    towerOfHanoi(n - 1, source, aux, dest);

    cout << "The disk " << n << " move from "
         << source << " to " << dest << endl;
    Count++;

    towerOfHanoi(n - 1, aux, dest, source);
    
}

int main()
{
    int a;

    cout << "Enter number of disks: "<<endl;
    cin >> a;

    towerOfHanoi(a, 'A', 'C', 'B');

    cout << "\nTotal number of moves = " << Count << endl;
    cout << "Expected moves = " << pow(2, a) - 1 << endl;

    return 0;
}