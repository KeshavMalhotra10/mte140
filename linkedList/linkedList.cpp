#include <iostream>
using namespace std;

template <typename T> // T is a blueprint for creating a class that can hold any data type

class Node
{
public:
    T element;  // Element contained in the node
    Node *next; // pointer to the next node
    Node()
    { // constructor with no arguments
        next = nullptr;
    }
    Node(T element)
    {
        this->element = element;
        next = nullptr;
    }
    void printList(Node<T> *head)
    {
        Node<string> *current = head;
        while (current != nullptr)
        {
            cout << current->element << endl;
            current = current->next;
        }
    }
    void addFirst(T element)
    {
        Node<T> *newNode = new Node<T>(element);

        newNode->next = head; // newNode's next pointer now stores address of the current first node
        head = newNode;       // the head pointer gets shifted to newNode(now 1st node)
        size++;
        if (tail == nullptr)
            tail = head; // If the list was empty, this new node is both the head and the tail
    }

    void addLast(T element)
    {
        if (tail == nullptr)
        {
            head = tail = new Node<T>(element);
            // if the list is empty, we want our head and tail to equal to this newNode
        }
        else
        {
            tail->next = newNode<T>(element);
            tail = tail->next;
        }
        size++;
    }
};

int main()
{
    // declare a head and tail
    Node<string> *head = nullptr; // these are pointers to nodes not nodes themselves
    Node<string> *tail = nullptr;

    // create the first node and insert it to the list
    head = new Node<string>("Chicago"); // head points to our first node "Chicago"
    tail = head;                        // tails also points to "Chicago"

    // create second node and insert it to list
    tail->next = new Node<string>("Denver"); // we create a new node that is next of Chicago using tail->next
    tail = tail->next;                       // we move the tail pointer to the last node

    // Create a third node and insert it to list
    tail->next = new Node<string>("Toronto");
    tail = tail->next;

    head->printList(head);
}
