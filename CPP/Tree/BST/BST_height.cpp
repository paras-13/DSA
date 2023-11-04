// Height of BST tree
/*  Time Complexity: O(n);
    Auxiliary space: O(n);
*/

#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *right;
    Node *left;
    Node(int x)
    {
        data = x;
        right = left = NULL;
    }
};
Node *insertNode(Node *root, int val)
{
    if (root == NULL)
        return new Node(val);
    if (root->data > val)
        root->left = insertNode(root->left, val);
    else if (root->data < val)
        root->right = insertNode(root->right, val);
    return root;
}

int height(Node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        int left_height = height(root->left);
        int right_height = height(root->right);
        if (left_height > right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}
int main()
{
    Node *root = NULL;
    int n, val;
    cout << "Enter number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        root = insertNode(root, val);
    }
    cout << "Height of the Binary Search Tree is: " << height(root);
    return 0;
}