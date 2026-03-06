#include <iostream>
using namespace std;
void printList(int list[], int size);
void bubbleSort(int list[], int size);
int main()
{
    int myList[] = {2, 9, 5, 4, 8, 1};
    printList(myList, 6);
    bubbleSort(myList, 6);
    printList(myList, 6);
}

void bubbleSort(int list[], int size)
{
    // use a sentinel to keep track if you need to sort
    bool continueSorting = true;

    while (continueSorting)
    {
        int numSwaps = 0;
        // iterate through list until second last member
        for (int i = 0; i < size - 1; i++)
        {
            if (list[i] > list[i + 1])
            {
                int temp = list[i];
                list[i] = list[i + 1];
                list[i + 1] = temp;
                numSwaps++;
            }
        }
        if (numSwaps == 0)
            continueSorting = false;
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
