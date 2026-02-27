#include <iostream>
using namespace std;
void selectionSort(int list[], int high);
void printList(int list[], int size);
int main()
{
    int myList[] = {7, 9, 1, 3, 4, 5};
    printList(myList, 6);
    selectionSort(myList, 5);
    printList(myList, 6);
}

void selectionSort(int list[], int high)
{
    if (high == 0)
        return;
    else
    {
        int maxIndex = high;
        for (int i = 0; i < high; i++)
        {
            if (list[i] > list[maxIndex])
            {
                maxIndex = i;
            }
        }
        swap(list[high], list[maxIndex]);
        return selectionSort(list, high - 1);
    }
}
void printList(int list[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << list[i];
    }
    cout << endl;
}
