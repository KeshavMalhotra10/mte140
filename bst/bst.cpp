#include <iostream>
using namespace std;
template <typename T>
class TreeNode
{
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
int main()
{
}