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
    void add(int index, T element)
    {
        if (index == 0)
            addFirst(element);
        else if (index == size)
        {
            addLast(element);
        }
        else
        {
            Node<T> *newNode = new Node<T>(element); // created the newNode with the value
            Node<T> *temp = head;                    // this will be what traverses through the list
            for (int i = 0; i < index - 1; i++)
            {
                // we loop until the index before where we want to insert
                temp = temp->next;
            }
            newNode->next = temp->next; // newNode points to the node of specified interest
            temp->next = newNode;       // and temp now points to newNode, meaning we successfully put newNode in the right place
            size++;
        }
    }

    T removeFirst() throw(runtime_error)
    {
        if (size == 0)
        {
            throw runtime_error("No elements in the list");
        }
        else
        {
            Node<T> *temp = head; // create a scout & point to the head(we will delete later on)
            head = head->next;    // shift head forward
            size--;               // decrease size
            if (head == nullptr)
                tail = nullptr;
            T element = temp->element; // store the value of temp so we can delete safely
            delete temp;
            return element;
        }
        }

    T removeLast() throw(runtime_error)
    {
        if (size == 0)
            throw runtime_error("No elements in the list");
        else if (size == 1)
        {
            Node<T> *temp = head;
            head = tail = nullptr;
            size = 0;
            T element = temp->element;
            delete temp;
            return element;
        }
        else
        {
            Node<T> *current = head;
            for (int i = 0; i < size - 2; i++)
                current = current->next;
            Node<T> temp = tail;
            tail = current;
            tail->next = nullptr;
            size--;
            T element = temp->element;
            delete temp;
            return element;
        }
    }
};

int main()

{
    LinkedList<int> *myLinkedList = new LinkedList<int>();
    myLinkedList->addFirst(0);
    myLinkedList->addLast(7);
    myLinkedList->add(1, 10);
    myLinkedList->printList();
}
