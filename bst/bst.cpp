#include <iostream>
#include <queue>
using namespace std;

// ─── TreeNode ────────────────────────────────────────────
template <typename T>
class TreeNode
{
public:
    T element;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T element)
    {
        this->element = element;
        left = nullptr;
        right = nullptr;
    }
};

// ─── BST ─────────────────────────────────────────────────
template <typename T>
class BST
{
private:
    TreeNode<T> *root;
    int size;

    // ── Traversal helpers ──
    void inorder(TreeNode<T> *node) const
    {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->element << " ";
        inorder(node->right);
    }

    void preorder(TreeNode<T> *node) const
    {
        if (node == nullptr)
            return;
        cout << node->element << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(TreeNode<T> *node) const
    {
        if (node == nullptr)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << node->element << " ";
    }

public:
    BST()
    {
        root = nullptr;
        size = 0;
    }

    int getSize() const { return size; }

    // ── Search (slide 11) ──────────────────────────────
    bool search(T element) const
    {
        TreeNode<T> *current = root; // start from root

        while (current != nullptr)
        {
            if (element < current->element)
                current = current->left; // go left
            else if (element > current->element)
                current = current->right; // go right
            else
                return true; // element found
        }
        return false; // element not in tree
    }

    // ── Insert (slides 12-13) ──────────────────────────
    bool insert(T element)
    {
        if (root == nullptr)
        { // tree is empty
            root = new TreeNode<T>(element);
            size++;
            return true;
        }

        // locate the parent node
        TreeNode<T> *parent = nullptr;
        TreeNode<T> *current = root;

        while (current != nullptr)
        {
            if (element < current->element)
            {
                parent = current;
                current = current->left;
            }
            else if (element > current->element)
            {
                parent = current;
                current = current->right;
            }
            else
                return false; // duplicate, not inserted
        }

        // attach new node to parent
        if (element < parent->element)
            parent->left = new TreeNode<T>(element);
        else
            parent->right = new TreeNode<T>(element);

        size++;
        return true;
    }

    // ── Delete (slides 56-62) ──────────────────────────
    bool remove(T element)
    {
        TreeNode<T> *parent = nullptr;
        TreeNode<T> *current = root;

        // locate the node to delete and its parent
        while (current != nullptr)
        {
            if (element < current->element)
            {
                parent = current;
                current = current->left;
            }
            else if (element > current->element)
            {
                parent = current;
                current = current->right;
            }
            else
                break; // node found
        }

        if (current == nullptr)
            return false; // element not in tree

        // ── Case 1: current has NO left child (slide 57) ──
        // Connect parent directly to current's right child
        if (current->left == nullptr)
        {
            if (parent == nullptr) // deleting the root
                root = current->right;
            else if (parent->left == current)
                parent->left = current->right;
            else
                parent->right = current->right;

            delete current;
        }
        // ── Case 2: current HAS a left child (slides 59-62) ──
        // Find the rightmost node in the left subtree (in-order predecessor)
        else
        {
            TreeNode<T> *parentOfRightMost = current;
            TreeNode<T> *rightMost = current->left;

            while (rightMost->right != nullptr)
            { // go as far right as possible
                parentOfRightMost = rightMost;
                rightMost = rightMost->right;
            }

            // copy rightMost's value into current node
            current->element = rightMost->element;

            // connect parentOfRightMost to rightMost's left child
            // special sub-case (slide 65): rightMost IS current->left
            if (parentOfRightMost->left == rightMost)
                parentOfRightMost->left = rightMost->left;
            else
                parentOfRightMost->right = rightMost->left;

            delete rightMost;
        }

        size--;
        return true;
    }

    // ── Traversals (slides 39-53) ──────────────────────
    void inorder() const
    {
        inorder(root);
        cout << endl;
    }
    void preorder() const
    {
        preorder(root);
        cout << endl;
    }
    void postorder() const
    {
        postorder(root);
        cout << endl;
    }

    // Breadth-first / level-order (slide 51)
    void breadthFirst() const
    {
        if (root == nullptr)
            return;

        queue<TreeNode<T> *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode<T> *current = q.front();
            q.pop();
            cout << current->element << " ";

            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);
        }
        cout << endl;
    }
};

// ─── Main ─────────────────────────────────────────────────
int main()
{
    BST<int> tree;

    // build the tree from slide 36: 60,55,100,45,57,67,107,59,101
    tree.insert(60);
    tree.insert(55);
    tree.insert(100);
    tree.insert(45);
    tree.insert(57);
    tree.insert(67);
    tree.insert(107);
    tree.insert(59);
    tree.insert(101);

    cout << "Inorder    (expect: 45 55 57 59 60 67 100 101 107): ";
    tree.inorder();

    cout << "Preorder   (expect: 60 55 45 57 59 100 67 107 101): ";
    tree.preorder();

    cout << "Postorder  (expect: 45 59 57 55 67 101 107 100 60): ";
    tree.postorder();

    cout << "BreadthFirst(expect:60 55 100 45 57 67 107 59 101): ";
    tree.breadthFirst();

    cout << "\nSearch 59: " << (tree.search(59) ? "Found" : "Not found") << endl;
    cout << "Search 99: " << (tree.search(99) ? "Found" : "Not found") << endl;

    // delete examples from slides 58, 62
    cout << "\nDelete 10 (Case 1 - no left child demo):\n";
    BST<int> tree2;
    tree2.insert(20);
    tree2.insert(10);
    tree2.insert(40);
    tree2.insert(16);
    tree2.insert(30);
    tree2.insert(80);
    tree2.insert(27);
    tree2.insert(50);
    cout << "Before: ";
    tree2.inorder();
    tree2.remove(10);
    cout << "After removing 10: ";
    tree2.inorder();

    cout << "\nDelete 20 (Case 2 - has left child demo):\n";
    cout << "Before: ";
    tree2.inorder();
    tree2.remove(20);
    cout << "After removing 20: ";
    tree2.inorder();

    return 0;
}