#include <iostream>
#include <string>
using namespace std;
void printNTimes(int n, string message);
int main()
{
    printNTimes(4, "Keshav");
}
void printNTimes(int n, string message)
{
    if (n == 0)
        return;

    cout << "message: " << message << endl;
    printNTimes(n - 1, message);
}
