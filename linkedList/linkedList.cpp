#include "linkedList.h"
#include <iostream>
using namespace std;

int main()
{
    LinkedList<int> list;

    // Test addFirst and addLast
    list.addFirst(5);
    list.addLast(10);
    list.addFirst(1);
    cout << "List: ";
    list.printList(); // 1 5 10

    // Test add at index
    list.add(1, 3);
    cout << "After add(1, 3): ";
    list.printList(); // 1 3 5 10

    // Test removeFirst and removeLast
    cout << "Removed first: " << list.removeFirst() << endl; // 1
    cout << "Removed last: " << list.removeLast() << endl;   // 10
    cout << "List: ";
    list.printList(); // 3 5

    // Test removeAt
    list.addLast(7);
    list.addLast(9);
    cout << "List before removeAt: ";
    list.printList();                                           // 3 5 7 9
    cout << "Removed at index 2: " << list.removeAt(2) << endl; // 7
    cout << "List: ";
    list.printList(); // 3 5 9

    // Test copy constructor
    LinkedList<int> copy(list);
    cout << "Copied list: ";
    copy.printList(); // 3 5 9

    // Test assignment operator
    LinkedList<int> assigned;
    assigned = list;
    cout << "Assigned list: ";
    assigned.printList(); // 3 5 9

    // Test iterator
    cout << "Using iterator: ";
    for (Iterator<int> it = list.begin(); it != list.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Range-based for loop (requires begin/end)
    cout << "Range-based for loop: ";
    for (auto &element : list)
    {
        cout << element << " ";
    }
    cout << endl;

    cout << "Final size: " << list.getSize() << endl;

    return 0;
}