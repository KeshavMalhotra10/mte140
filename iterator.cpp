// ITERATOR CLASS - A "smart pointer" that lets you traverse the linked list
// Think of it as a bookmark that points to a node and knows how to move forward

template <typename T>
class Iterator : public std::iterator<std::forward_iterator_tag, T>
{
    // Inherits from std::iterator to tell C++ this is a forward iterator
    // (can only move forward, not backward like a bidirectional iterator)
    // This inheritance allows the iterator to work with STL algorithms

public:
    // CONSTRUCTOR - Creates an iterator pointing to a specific node
    Iterator(Node<T> *p) : current(p) {}
    // Example: Iterator<int> it(head); // creates iterator pointing to head node

    // PREFIX INCREMENT OPERATOR (++it)
    // Called when you write: ++it
    Iterator operator++()
    {
        current = current->next; // Move to next node
        return *this;            // Return the updated iterator
    }
    // Example:
    //   ++it;  // moves to next node and returns the new position

    // POSTFIX INCREMENT OPERATOR (it++)
    // Called when you write: it++
    // The 'int' parameter is a dummy to distinguish from prefix
    Iterator operator++(int)
    {
        Iterator temp(current);  // Save the OLD position
        current = current->next; // Move to next node
        return temp;             // Return the OLD position (before increment)
    }
    // Example:
    //   Iterator old = it++;  // old gets current position, it moves forward
    // Difference: ++it returns new position, it++ returns old position

    // DEREFERENCE OPERATOR (*)
    // Called when you write: *it
    // Returns the actual data stored in the node
    T &operator*()
    {
        return current->element; // Return reference to the element
    }
    // Example:
    //   cout << *it;  // prints the element at current position
    //   *it = 10;     // you can also modify the element

    // EQUALITY OPERATOR (==)
    // Called when you write: it1 == it2
    // Checks if two iterators point to the same node
    bool operator==(const Iterator<T> &iterator) const
    {
        return current == iterator.current; // Compare node pointers
    }
    // Example:
    //   if (it == list.end()) { ... }  // check if reached end

    // INEQUALITY OPERATOR (!=)
    // Called when you write: it1 != it2
    // Checks if two iterators point to different nodes
    bool operator!=(const Iterator<T> &iterator) const
    {
        return current != iterator.current; // Compare node pointers
    }
    // Example:
    //   while (it != list.end()) { ... }  // loop until end

private:
    Node<T> *current; // The actual node pointer this iterator wraps
    // This is the "bookmark" - it keeps track of where we are in the list
};

/*
==============================================================================
HOW ITERATORS WORK - PRACTICAL EXAMPLES
==============================================================================

Example 1: Manual iteration
----------------------------
LinkedList<int> list;
list.addLast(1);
list.addLast(2);
list.addLast(3);

// Create iterator pointing to beginning
Iterator<int> it = list.begin();

cout << *it;     // Output: 1 (dereference to get value)
++it;            // Move to next node
cout << *it;     // Output: 2
++it;            // Move to next node
cout << *it;     // Output: 3

Example 2: Loop with iterators
-------------------------------
for (Iterator<int> it = list.begin(); it != list.end(); ++it)
{
    cout << *it << " ";  // Prints: 1 2 3
}

How this works:
1. it = list.begin()     → Iterator points to first node (1)
2. it != list.end()      → Check if not at end (true)
3. *it                   → Get value (1), print it
4. ++it                  → Move to next node (2)
5. it != list.end()      → Check again (true)
6. *it                   → Get value (2), print it
7. ++it                  → Move to next node (3)
8. ... and so on until it == list.end() (which points to nullptr)

Example 3: Range-based for loop (requires iterators)
-----------------------------------------------------
for (int& element : list)
{
    cout << element << " ";  // Prints: 1 2 3
}

Behind the scenes, C++ converts this to:
for (auto it = list.begin(); it != list.end(); ++it)
{
    int& element = *it;
    cout << element << " ";
}

Example 4: Modifying elements through iterator
-----------------------------------------------
for (Iterator<int> it = list.begin(); it != list.end(); ++it)
{
    *it = *it * 2;  // Double each element
}
// List is now: 2 4 6

==============================================================================
WHY USE ITERATORS?
==============================================================================

1. ABSTRACTION: You don't need to know about Node pointers
   - Without iterator: node->next->next->element
   - With iterator:    ++it; ++it; *it;

2. STANDARDIZATION: Works like iterators for vector, list, set, etc.
   - Same syntax across all STL containers

3. SAFETY: Iterator handles pointer logic, reducing bugs

4. COMPATIBILITY: Works with STL algorithms
   - std::find(list.begin(), list.end(), 5);
   - std::sort(list.begin(), list.end());

==============================================================================
ITERATOR vs RAW NODE POINTER
==============================================================================

Raw pointer way (messy):
Node<int>* ptr = head;
while (ptr != nullptr) {
    cout << ptr->element;
    ptr = ptr->next;
}

Iterator way (clean):
for (Iterator<int> it = list.begin(); it != list.end(); ++it) {
    cout << *it;
}

The iterator hides the complexity of Node pointers!
*/