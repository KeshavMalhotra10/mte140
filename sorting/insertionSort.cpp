#include <iostream>

using namespace std;
void insertSort(int list[], int size);
void printList(int list[], int size);
int main()
{
    int unsortedList[] = {2, 9, 5, 4, 8, 1, 6};
    printList(unsortedList, 7);
    insertSort(unsortedList, 7);
    printList(unsortedList, 7);
}

void insertSort(int list[], int size)
{
    // Start at the first value, i = 1
    for (int i = 1; i < size; i++)
    {
        // for the index ahead of it, continue looking until find a number smaller
        // any number larger shift to the right 1 index
        int value = list[i];
        int j = i - 1;                    // compare with index to the left
        while (value < list[j] && j >= 0) // and condition necessary, do not use or
        {
            list[j + 1] = list[j];
            j--;
        }
        // now that we have a smaller number before it
        list[j + 1] = value;
    }
}

void printList(int list[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}
