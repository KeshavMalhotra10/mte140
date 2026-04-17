#include <iostream>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left; // pointer to a treenode object
    TreeNode<T> *right;

    TreeNode(const T &v)
    {
        val = v;
        left = nullptr;
        right = nullptr;
    }
};

template <typename T>
class BST
{
private:
    int size;
    TreeNode<T> *root;

public:
    BST()
    {
        root = nullptr;
        size = 0;
    }
    BST(const T &v)
    {
        TreeNode<T> *newNode = new TreeNode<T>(v);
        root = newNode;
        size++;
    }
    bool search(const T &element)
    {
        TreeNode<T> *current = root;
        while (current != nullptr)
        {
            if (element < current->val)
                current = current->left;
            else if (element > current->val)
                current = current->right;
            else
                return true;
        }
        return false;
    }
    void add(const T &element)
    {
        TreeNode<T> *newNode = new TreeNode<T>(element);
        if (size == 0)
            root = newNode;
        else
        {
            TreeNode<T> *current = root;
            while (current != nullptr)
            {
                if (element < current->val)
                {
                    if (current->left == nullptr)
                    { // find the gap and insert
                        current->left = newNode;
                        return;
                    }
                    current = current->left;
                }

                else if (element > current->val)
                {
                    if (current->right == nullptr)
                    {
                        current->right = newNode;
                        return;
                    }
                    current = current->right;
                }
                else
                    return;
            }
        }
        size++;
    }
    void inOrder(TreeNode<T> *root)
    {
        if (root == nullptr)
            return;
        inOrder(root->left);
        cout << root->val << " ";
        inOrder(root->right);
    }
    void inOrder()
    {
        inOrder(root);
    }
    void postOrder(TreeNode<T> *root)
    {
        if (root == nullptr)
            return;
        postOrder(root->left);
        postOrder(root->right);
        cout << root->val << " ";
    }
    void postOrder()
    {
        postOrder(root);
    }
};

int main()
{
    BST<int> myBST(1);
    myBST.add(3);
    myBST.add(4);
    myBST.add(2);
    myBST.inOrder();
    myBST.postOrder();
}