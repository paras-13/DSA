// Inorder Traversal (Iterative approach)
// Inorder traversal is a type of depth-first traversal.
// In this traversal, the left subtree is visited first, then the root, and finally the right subtree.

// Time complexity : O(n)
// Space complexity : O(h), where h is the height of the tree.

// Algorithm:
// 1. Create an empty stack.
// 2. Initialize the current node as the root node.
// 3. Push the current node to the stack and set the current node to the left child of the current node.
// 4. If the current node is NULL and the stack is not empty, pop the top element from the stack, print it, and set the current node to the right child of the popped element.

// Implementation:
#include <iostream>
#include <stack>
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
    if (!root)
        return;
    stack<Node *> st;
    Node *node = root;
    while (true)
    {
        if (node)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty())
                break;
            node = st.top();
            st.pop();
            cout << node->data << " ";
            node = node->right;
        }
    }
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