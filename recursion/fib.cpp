#include <iostream>
using namespace std;

int fibOutput(int index)
{
    if (index == 0)
        return 0;
    else if (index == 1)
        return 1;
    else
        return fibOutput(index - 1) + fibOutput(index - 2);
}
// 0 1 1 2 3 5 8
int main()
{
    cout << fibOutput(10);
}

// note this fibonacci function is very inefficient O(2^n)