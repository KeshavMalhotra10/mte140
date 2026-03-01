#include <iostream>
#include <string>
using namespace std;

// Case 1: Reduction: you have a collection, you handle one item, and hand the rest of the collection for function to handle
void reverseString(string s);

// Case 2: Decision: for each item you have a yes or no decision, include item or don't include item
void flip(int n, string current);

// Case 3: Exploration, you are at some coordinate (x,y) and must try every legal move
void printJumps(int current, int target, string path);

int main()
{
    string myString;
    flip(2, myString);
}

void reverseString(string s)
{
    // basecase
    if (s.size() == 0)
        return;
    else
    {
        reverseString(s.substr(1, s.size() - 1));
        cout << s[0];
    }
}

void flip(int n, string current)
{
    // basecase:
    if (n == 0)
    {
        cout << current << " ";
        return;
    }
    // recursive case
    else
    {
        flip(n - 1, current + "H");
        flip(n - 1, current + "T");
    }
}

void printJumps(int current, int target, string path)
{
    if (current == target)
    {
        cout << path << " ";
        return;
    }
    else if (current > target)
        return;

    printJumps(current + 1, target, path + " 1");
    printJumps(current + 2, target, path + " 2");
}