#include <iostream>
using namespace std;

int recursiveSearch(const int list[], int key, int low, int high);
int main()
{
    int myList[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << recursiveSearch(myList, 2, 0, size(myList) - 1);
}

int recursiveSearch(const int list[], int key, int low, int high) // returns the index of the key-value
{
    // if number is < key, then search left half
    // if number is > key, then search right half
    // if number == key, then return value

    int middle = (low + high) / 2;
    if (low > high)
        return INT_MIN;
    else if (key < list[middle])
        return recursiveSearch(list, key, low, middle - 1);
    else if (key > list[middle])
        return recursiveSearch(list, key, middle + 1, high);
    else
        return middle;
}