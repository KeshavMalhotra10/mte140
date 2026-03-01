#include <iostream>
#include <string>
using namespace std;

void countDown(int n);
int powerFunction(double base, double power);
int maxArray(int arr[], int size, int index);
int sumEvens(int arr[], int size, int index);
int countVowels(string s, int index);
int countWays(int n);
void printPaths(int m, int n, string path);

int main()
{
    string myString = "hello world";
    cout << countVowels(myString, 0);
}

void countDown(int n)
{
    // basecase
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    // recursive step
    else
    {
        cout << n << endl;
        countDown(n - 1);
    }
}

int powerFunction(double base, double power)
{
    // basecase
    if (power == 0)
        return 1;
    else
    {
        return base * powerFunction(base, power - 1);
    }
}

int maxArray(int arr[], int size, int index)
{
    // basecase
    if (size - 1 == index)
        return arr[index];
    // recursive step
    else
    {
        int maxOfRest = maxArray(arr, size, index + 1);
        if (arr[index] > maxOfRest)
            return arr[index];
        else
            return maxOfRest;
    }
}

int sumEvens(int arr[], int size, int index)
{
    if (index == size)
    {
        return 0;
    }
    else if (arr[index] % 2 == 0)
        return arr[index] + sumEvens(arr, size, index + 1);
    else
        return sumEvens(arr, size, index + 1);
}

int countVowels(string s, int index)
{
    if (index == s.size())
        return 0;
    else if (s[index] == 'a' || s[index] == 'e' || s[index] == 'i' || s[index] == 'u' || s[index] == 'o')
        return 1 + countVowels(s, index + 1);
    else
        return countVowels(s, index + 1);
}

int countWays(int n)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;

    return countWays(n - 3) + countWays(n - 2) + countWays(n - 1);
}
void printPaths(int m, int n, string path)
{
    // basecase
    if (m == 1 && n == 1)
    {
        cout << path << endl;
        return;
    }
    // recursive cases
    if (n > 1)
        printPaths(m, n - 1, path + "R");
    if (m > 1)
        printPaths(m - 1, n, path + "D");
}