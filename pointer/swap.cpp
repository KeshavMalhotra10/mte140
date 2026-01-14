#include <iostream>
using namespace std;

// swap by value(doesn't swap)
void swapByValue(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}

// effectively swaps
void swapByReference(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
    int x = 5;
    int y = 6;
    cout << "original: " << x << " " << y << endl;
    swapByValue(x, y);
    cout << "after: " << x << " " << y << endl;
    cout << endl;

    cout << "original: " << x << " " << y << endl;
    swapByReference(x, y);
    cout << "after: " << x << " " << y << endl;
}