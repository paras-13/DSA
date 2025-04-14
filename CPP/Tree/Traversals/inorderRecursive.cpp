// Inorder Traversal (recursive approach)
// Inorder traversal is a type of depth-first traversal.
// In this traversal, the left subtree is visited first, then the root, and finally the right subtree.
// This traversal is used to get the elements of the tree in non-decreasing order.

// *Time complexity : O(n)
// *Space complexity : O(h), where h is the height of the tree.
// In the worst case, the height of the tree can be n (in case of a skewed tree),
// so the space complexity is O(n).

// Algorithm: LPR
// 1. Traverse the left subtree by recursively calling the inorder function.
// 2. Visit the root node.
// 3. Traverse the right subtree by recursively calling the inorder function.

// Implementation:
#include <iostream>
#include <queue>
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
        left = right = NULL;
    }
};

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->right->right->right = new Node(9);
    inorder(root);

    // Output:- 8 4 2 5 1 6 3 7 9
}