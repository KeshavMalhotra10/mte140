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
        Node<T> *newNode = new Node<T>(v);
        if (head == nullptr)
        {
            head = tail = newNode;
            newNode->next = nullptr;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }
    void addLast(const T &v)
    {
        Node<T> *newNode = new Node<T>(v);
        newNode->next = nullptr;
        if (tail == nullptr)
        {
            tail = head = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
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
    int getSize()
    {
        return size;
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

    T front()
    {
        return head->value;
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
    bool sameSequence(const LinkedList &other)
    {
        Node<T> *a = this->head;
        Node<T> *b = other.head; // don't use ->, other is not a pointer
        while (a != nullptr && b != nullptr)
        {
            if (a->value != b->value)
                return false;
            else
            {
                a = a->next;
                b = b->next;
            }
        }
        return true;
    }
    Node<T> *kFromEnd(int k)
    {
        // we are assuming size is not known
        int unknownSize = 0;
        Node<T> *scout = head;
        while (scout != nullptr)
        {
            unknownSize++;
            scout = scout->next;
        }
        int kPos = unknownSize - k - 1;
        scout = head;
        for (int i = 0; i < kPos; i++)
        {
            scout = scout->next;
        }
        return scout;
    }

    bool isPalindrome() const
    {
        LinkedList<T> stack;
        Node<T> *current = head;

        // we populate fullStack
        while (current != nullptr)
        {
            stack.addFront(current->value);
            current = current->next;
        }

        current = head;
        while (current != nullptr)
        {
            if (current->value != stack.front())
                return false;
            else
            {
                current = current->next;
                stack.removeFirst();
            }
        }
        return true;
    }
    void removeAllSpecificValue(const T &v)
    {
        Node<T> *cur = head;
        while (cur->next != nullptr)
        {
            if (head->value == v)
            {
                Node<T> *temp = head;
                head = head->next;
                cur = head;
                delete temp;
                size--;
            }
            else if (cur->next->value == v)
            {
                Node<T> *temp = cur->next;
                cur->next = temp->next;
                delete temp;
                size--;
            }
            else
                cur = cur->next;
        }
    }
    Node<T> *returnMiddleNode()
    {
        Node<T> *slow = head;
        Node<T> *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
int main()
{
    // LinkedList<int> myLinkedList(7);
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

    // LinkedList<int> secondList(1);
    // secondList.addFront(2);
    // secondList.addFront(1);
    // secondList.addFront(2);
    // secondList.addFront(1);
    // secondList.removeDupe();
    // secondList.printList();

    LinkedList<int> firstList;
    firstList.addFront(1);
    firstList.addFront(2);
    firstList.addFront(3);

    LinkedList<int> secondList;
    secondList.addFront(1);
    secondList.addFront(2);
    secondList.addFront(3);

    bool sameSequence = firstList.sameSequence(secondList); // don't need to put ampersand "&" since already in function
    cout << sameSequence << endl;

    LinkedList<int> thirdList;
    thirdList.addFront(5);
    thirdList.addFront(4);
    thirdList.addFront(3);
    thirdList.addFront(2);
    thirdList.addFront(1);

    Node<int> *kthNode = thirdList.kFromEnd(2);
    cout << "K'th Node: " << kthNode->value << endl;

    // Palindrome
    LinkedList<char> palindromeString;
    palindromeString.addFront('R');
    palindromeString.addFront('A');
    palindromeString.addFront('C');
    palindromeString.addFront('E');
    palindromeString.addFront('C');
    palindromeString.addFront('A');
    palindromeString.addFront('B');

    cout << palindromeString.isPalindrome();

    LinkedList<int> numbers;
    numbers.addFront(7);
    numbers.addFront(7);
    numbers.addFront(7);
    numbers.addFront(7);
    numbers.addFront(1);
    numbers.addFront(7);
    cout << endl;
    numbers.printList();
    numbers.removeAllSpecificValue(7);
    numbers.printList();

    LinkedList<int> middleNodeList;
    middleNodeList.addLast(1);
    middleNodeList.addLast(2);
    middleNodeList.addLast(3);
    middleNodeList.addLast(4);
    Node<int> *middleNode = middleNodeList.returnMiddleNode();
    cout << "middle node value: " << middleNode->value << endl;
}