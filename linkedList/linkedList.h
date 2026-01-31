#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdexcept>
#include <iostream>
#include <iterator>
using namespace std;

template <typename T> // allows us to make a universal datatype T(we can input any datatype when using the class)
class Node
{
public:
    T element;
    Node<T> *next; // next is a pointer to a node of datatype T

    Node() : next(nullptr) {}                       // this says, Node constructor with no paramters, initialize next to nullptr
    Node(const T &e) : element(e), next(nullptr) {} // Node constructor with parameter e, initialize element to e, next to nullptr
};

template <typename T>
class Iterator : public std::iterator<std::forward_iterator_tag, T> // iterators are super useful for making our code more concise
{
public:
    Iterator(Node<T> *p) : current(p) {}

    Iterator operator++() // Prefix ++
    {
        current = current->next;
        return *this;
    }

    Iterator operator++(int) // Postfix ++
    {
        Iterator temp(current);
        current = current->next;
        return temp;
    }

    T &operator*()
    {
        return current->element;
    }

    bool operator==(const Iterator<T> &iterator) const
    {
        return current == iterator.current;
    }

    bool operator!=(const Iterator<T> &iterator) const
    {
        return current != iterator.current;
    }

private:
    Node<T> *current; // current is a pointer to a node of type T
};

template <typename T>
class LinkedList
{
public:
    LinkedList(); // consturctor with no-args
    LinkedList(const LinkedList<T> &list);
    ~LinkedList(); // destructor
    LinkedList<T> &operator=(const LinkedList<T> &list);

    void addFirst(const T &e); // we use const T &e for efficiency, passing by reference means use initial value, but const makes it so value can't be changed
    void addLast(const T &e);
    void add(int index, const T &e);
    T removeFirst();
    T removeLast();
    T removeAt(int index);
    void printList() const;
    int getSize() const { return size; }
    void removeDupe()
    {
    }

    Iterator<T> begin() const { return Iterator<T>(head); }
    Iterator<T> end() const { return Iterator<T>(nullptr); }

private:
    Node<T> *head;
    Node<T> *tail;
    int size;
};

// Constructor
template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

// Copy constructor
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &list) : head(nullptr), tail(nullptr), size(0)
{
    Node<T> *current = list.head;
    while (current != nullptr)
    {
        addLast(current->element);
        current = current->next;
    }
}

// Destructor
template <typename T>
LinkedList<T>::~LinkedList()
{
    while (head != nullptr)
    {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }
}

// Assignment operator
template <typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &list)
{
    if (this != &list)
    {
        // Clear existing list
        while (head != nullptr)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }

        head = tail = nullptr;
        size = 0;

        // Copy new list
        Node<T> *current = list.head;
        while (current != nullptr)
        {
            addLast(current->element);
            current = current->next;
        }
    }
    return *this;
}

// Add to beginning
template <typename T>
void LinkedList<T>::addFirst(const T &e)
{
    Node<T> *newNode = new Node<T>(e);
    newNode->next = head;
    head = newNode;
    size++;

    if (tail == nullptr)
        tail = head;
}

// Add to end
template <typename T>
void LinkedList<T>::addLast(const T &e)
{
    if (tail == nullptr) // this can only happen if they are 0 nodes in the LL
    {
        head = tail = new Node<T>(e);
    }
    else
    {
        tail->next = new Node<T>(e);
        tail = tail->next;
    }
    size++;
}

// Add at index
template <typename T>
void LinkedList<T>::add(int index, const T &e)
{
    if (index == 0)
        addFirst(e);
    else if (index >= size)
        addLast(e);
    else
    {
        Node<T> *current = head;
        for (int i = 1; i < index; i++)
            current = current->next;

        Node<T> *temp = current->next;
        current->next = new Node<T>(e);
        current->next->next = temp;
        size++;
    }
}

// Remove first
template <typename T>
T LinkedList<T>::removeFirst()
{
    if (size == 0)
        throw runtime_error("No elements in the list");

    Node<T> *temp = head;
    head = head->next;
    if (head == nullptr)
        tail = nullptr;

    size--;
    T element = temp->element;
    delete temp;
    return element;
}

// Remove last
template <typename T>
T LinkedList<T>::removeLast()
{
    if (size == 0)
        throw runtime_error("No elements in the list");

    if (size == 1)
        return removeFirst();

    Node<T> *current = head;
    for (int i = 0; i < size - 2; i++)
        current = current->next;

    Node<T> *temp = tail;
    tail = current;
    tail->next = nullptr;
    size--;
    T element = temp->element;
    delete temp;
    return element;
}

// Remove at index
template <typename T>
T LinkedList<T>::removeAt(int index)
{
    if (index < 0 || index >= size)
        throw runtime_error("Index out of range");

    if (index == 0)
        return removeFirst();

    if (index == size - 1)
        return removeLast();

    Node<T> *previous = head;
    for (int i = 1; i < index; i++)
        previous = previous->next;

    Node<T> *current = previous->next;
    previous->next = current->next;
    size--;
    T element = current->element;
    delete current;
    return element;
}

// Print list
template <typename T>
void LinkedList<T>::printList() const
{
    Node<T> *current = head;
    while (current != nullptr)
    {
        cout << current->element << " ";
        current = current->next;
    }
    cout << endl;
}

#endif