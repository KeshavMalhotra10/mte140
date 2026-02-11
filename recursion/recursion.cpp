#include <iostream>
using namespace std;

// Recurison is a problem solving technique where a function solves a problem
// by calling itself on a much smaller(simpler) version of th same problem until it reaches the basecase

/*
Steps for recursion:
Basecase: This is the stopping condition that prevents infinite recursion
Recursive Case: Functions calls itself with a smaller simpler input
*/
int factorial(int number);
double recursivePower(double x, int n); // this function calculates x^n
int main()
{
    // int facOutput = factorial(4);
    // cout << facOutput << endl;

    double power = recursivePower(3, 8);
    cout << power << endl;
}

int factorial(int number)
{
    if (number == 0)
        return 1;
    return number * factorial(number - 1);
}

double recursivePower(double x, int n)
{
    if (n == 0)
        return 1;
    if (n < 0)
    {
        return recursivePower(1.0 / x, n * -1);
    }
    double half = recursivePower(x, n / 2);
    if (n % 2 == 0)
        return half * half;
    return x * half * half;
}