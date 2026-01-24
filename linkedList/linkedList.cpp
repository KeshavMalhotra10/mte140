template <typename T> // blueprint for creating a class that can hold any data type

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
};
