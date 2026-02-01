// This code is a doubly linked list implementation
#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T value; // we call it element in class but I prefer value
    Node<T> *next;
    Node<T> *prev;

    Node(const T &v)
    {
        value = v;
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>
class doublyLinkedList
{
private:
    int size;
    Node<T> *head;
    Node<T> *tail;

public:
    doublyLinkedList()
    {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }
    doublyLinkedList(const T &v)
    {
        size = 1;
        Node<T> *newNode = new Node<T>(v);
        head = newNode;
        tail = newNode;
        newNode->next = nullptr;
        newNode->prev = nullptr;
    }
    ~doublyLinkedList() {}
    void printList()
    {
        Node<T> *cur = head;
        while (cur != nullptr)
        {
            cout << cur->value << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    void addFront(const T &v)
    {
        Node<T> *newNode = new Node<T>(v);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            head->prev = newNode;
            newNode->next = head;
            newNode->prev = nullptr;
            head = newNode;
        }
        size++;
    }

    void addLast(const T &v)
    {
        if (tail == nullptr)
        {
            addFront(v);
        }
        else
        {
            Node<T> *newNode = new Node(v);
            newNode->next = nullptr;
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
            size++;
        }
    }
    void add(int index, const T &v)
    {
        if (index == 0)
        {
            addFront(v);
        }
        else if (index == size)
        {
            addLast(v);
        }
        else
        {
            Node<T> *newNode = new Node<T>(v);
            Node<T> *current = head;
            for (int i = 0; i < index - 1; i++)
            {
                current = current->next;
            }
            Node<T> *temp = current->next;
            newNode->next = temp;
            newNode->prev = current;
            current->next = newNode;
            temp->prev = newNode;
            size++;
        }
    }

    void removeFront()
    {
        if (size == 0)
        {
            return;
        }
        else if (size == 1)
        {
            Node<T> *temp = head;
            head = tail = nullptr;
            delete temp;
            size--;
        }
        else
        {
            Node<T> *temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
            size--;
        }
    }

    void removeLast()
    {
        if (size == 0)
            return;
        else if (size == 1)
        {
            Node<T> *temp = head;
            head = tail = nullptr;
            delete temp;
            size--;
        }
        else
        {
            Node<T> *temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
            size--;
        }
    }

    void remove(int index)
    {
        if (size == 0 || size == 1)
            return removeFront();
        else if (index == size - 1)
        {
            return removeLast();
        }
        else
        {
            Node<T> *cur = head;
            for (int i = 0; i < index - 1; i++)
            {
                cur = cur->next;
            }
            Node<T> *temp = cur->next;
            cur->next = temp->next;
            temp->next->prev = cur;
            delete temp;
            size--;
        }
    }
    int getSize() const
    {
        return size;
    }
};

int main()
{
    doublyLinkedList<int> newList;
    newList.addLast(4);
    newList.addLast(5);
    newList.addLast(6);
    newList.add(3, 100);
    newList.printList();
    newList.remove(2);
    newList.printList();
    int listSize = newList.getSize();
    cout << listSize;
}