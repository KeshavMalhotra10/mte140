#include <iostream>
using namespace std;
template <typename T>
class Node
{
public:
    T value;
    Node<T> *next;

    Node(const T &element)
    {
        value = element;
        next = nullptr;
    }
};

template <typename T>
class LinkedList
{
private:
    int size;
    Node<T> *head;
    Node<T> *tail;

public:
    LinkedList()
    {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }
    LinkedList(const T &v)
    {
        Node<T> *newNode = new Node<T>(v);
        head = newNode;
        tail = newNode;
        size = 1;
    }
    ~LinkedList()
    {
        clear();
    }
    void printList()
    {
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void addFront(const T &v)
    {
        Node<T> *newNode = new Node(v);
        newNode->next = head;
        head = newNode;
        size++;
    }
    void addLast(const T &v)
    {
        Node<T> *newNode = new Node(v);
        tail->next = newNode;
        tail = newNode;
        size++;
    }
    void add(int index, const T &v)
    {
        Node<T> *newNode = new Node(v);
        Node<T> *temp = head;
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }
    void removeFirst()
    {
        if (head == nullptr)
            return;
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    void removeLast()
    {
        if (size == 0)
            return;
        if (size == 1)
            return removeFirst();
        Node<T> *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        tail = temp;
        temp = temp->next;
        delete temp;
        tail->next = nullptr;
        size--;
    }
    void remove(int index)
    {
        if (index == 0)
            return removeFirst();
        if (index == size - 1)
            return removeLast();
        else
        {
            Node<T> *temp = head;
            Node<T> *removedNode = head;
            for (int i = 0; i < index - 1; i++)
            {
                temp = temp->next;
            }
            removedNode = temp->next;
            temp->next = temp->next->next;
            delete removedNode;
            size--;
        }
    }
    void clear()
    {
        while (head != nullptr)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }

    void removeDupe()
    {
        Node<T> *current = head;
        while (current != nullptr)
        {
            Node<T> *scout = current;
            while (scout->next != nullptr)
            {
                if (scout->next->value == current->value)
                {
                    Node<T> *duplicate = scout->next;
                    scout->next = duplicate->next;
                    delete duplicate;
                    size--;
                }
                else
                    scout = scout->next;
            }
            current = current->next;
        }
    }
};

int main()
{
    LinkedList<int> myLinkedList(7);
    // myLinkedList.addFront(6);
    // myLinkedList.addLast(4);
    // myLinkedList.add(1, 6);
    // myLinkedList.printList();
    // myLinkedList.removeFirst();
    // myLinkedList.printList();
    // myLinkedList.removeLast();
    // myLinkedList.printList();
    // myLinkedList.addLast(9);
    // myLinkedList.addLast(10);
    // myLinkedList.remove(2);
    // myLinkedList.printList();

    LinkedList<int> secondList(1);
    secondList.addFront(2);
    secondList.addFront(1);
    secondList.addFront(2);
    secondList.addFront(1);
    secondList.removeDupe();
    secondList.printList();
}