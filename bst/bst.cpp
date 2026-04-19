#include <iostream>
#include <queue> //only used for bfs
#include <stack> //only used for dfs
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

    bool remove(const T &element) // fix this remove function
    {
        if (!search(element))
            return false;
        else if (element == root->val)
        {
            delete root;
            size--;
        }
        TreeNode<T> *current = root;
        TreeNode<T> *temp = root;
        while (current != nullptr)
        {
            if (element < current->val)
            {
                if (current->left->val == element)
                {
                    temp = current->left;
                    current->left = temp->left;
                    delete temp;
                    size--;
                    return true;
                }
            }
            else if (element > current->val)
            {
                if (current->right->val == element)
                {
                    temp = current->right;
                    current->right = temp->right;
                    delete temp;
                    size--;
                    return true;
                }
            }
        }
    }

    void inOrder(TreeNode<T> *root) // 1+2 --> '1' = left,  '+' = print, '2' = right
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
    void postOrder(TreeNode<T> *root) // 12+ --> '1' = left, '2' = right, '+' = print
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
    void preOrder(TreeNode<T> *root) // +12 --> '+' = print,  '1' = left, '2' = right
    {
        if (root == nullptr)
            return;
        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
    void preOrder()
    {
        preOrder(root);
    }
    void bfs(TreeNode<T> *root)
    {
        if (root == nullptr) // indicates BST empty
            return;
        queue<TreeNode<T> *> q; // create a queue q that holds pointers to TreeNodes
        q.push(root);
        while (!q.empty())
        {                                     // while our queue is not empty
            TreeNode<T> *current = q.front(); // look at top at queue
            q.pop();                          // pop it
            cout << current->val << ' ';      // print the value
            if (current->left != nullptr)     // if a left child exists, then insert into queue
                q.push(current->left);
            if (current->right != nullptr)
            { // if right child exists, then insert into queue
                q.push(current->right);
            }
        }
    }
    void bfs()
    {
        bfs(root);
    }
    void dfs(TreeNode<T> *root)
    {
        if (root == nullptr)
            return;
        stack<TreeNode<T> *> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode<T> *current = s.top();
            s.pop();
            cout << current->val << " ";
            // push right first then left for DFS
            if (current->right != nullptr)
                s.push(current->right);
            if (current->left != nullptr)
                s.push(current->left);
        }
    }
    void dfs()
    {
        dfs(root);
    }

    int minVal(TreeNode<T> *root)
    {
        TreeNode<T> *current = root;
        while (current->left != nullptr)
        {
            current = current->left;
        }
        cout << current->val << endl;
        return current->val;
    }
    int minVal()
    {
        return minVal(root);
    }
    int sumBST(TreeNode<T> *root)
    {
        if (root == nullptr)
            return 0;
        return root->val + sumBST(root->left) + sumBST(root->right);
    }
    int sumBST()
    {
        return sumBST(root);
    }
    int countNodes(TreeNode<T> *root)
    {
        if (root == nullptr)
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right); // root nodes is one node, and then you repeat recursively for left and right childnodes
    }
    int countNodes()
    {
        return countNodes(root);
    }
};

int main()
{
    BST<int> myBST(10);
    myBST.add(5);
    myBST.add(60);
    myBST.add(3);
    myBST.add(7);
    myBST.add(30);
    myBST.add(70);
    cout << myBST.countNodes();
}