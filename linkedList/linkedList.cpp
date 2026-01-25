#include <iostream>
using namespace std;

template <typename T> // T is a blueprint for creating a class that can hold any data type

class Node
{
public:
    T element;     // Element contained in the node
    Node<T> *next; // pointer to the next node, we specified type of node for clarity
    Node()
    { // constructor with no arguments
        next = nullptr;
    }
    Node(T element) // constructor
    {
        this->element = element;
        next = nullptr;
    }
};

template <typename T> // the class must have template to use T and work for any datatype
class LinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    // constructor -> initializes the list to nullptr and size 0
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    };
    // Print the whole list
    void printList()
    {
        Node<T> *current = head;
        while (current != nullptr)
        {
            cout << current->element << endl;
            current = current->next;
        }
    }

    // add a node to the beginning of list
    void addFirst(T element)
    {
        Node<T> *newNode = new Node<T>(element);

        newNode->next = head; // newNode's next pointer now stores address of the current first node
        head = newNode;       // the head pointer gets shifted to newNode(now 1st node)
        size++;
        if (tail == nullptr)
            tail = head; // If the list was empty, this new node is both the head and the tail
    }

    // add a node to the end of a list
    void addLast(T element)
    {
        if (tail == nullptr)
        {
            head = tail = new Node<T>(element);
            // if the list is empty, we want our head and tail to equal to this newNode
        }
        else
        {
            tail->next = new Node<T>(element);
            tail = tail->next;
        }
        size++;
    }
};

int main()

{
    LinkedList<int> *myLinkedList = new LinkedList<int>();
    myLinkedList->addFirst(0);
    myLinkedList->addLast(7);
    myLinkedList->printList();
}
