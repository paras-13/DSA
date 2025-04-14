// Preorder Traversal (Iterative approach)
// Preorder Traversal is a type of depth first search traversal
// In this traversal root is visited first, then left subtree and then right subtree

// Time complexity : O(n)
// Space complexity : O(h), where h is the height of the tree.

// Algorithm
// Create an empty stack, and push root value
// Step 2: While stack is not empty, pop the top node and process it
// Step 3: If popped node has a right child, push it onto the stack
// Step 4: If popped node has a left child, push it onto the stack

// Code
#include <iostream>
#include <stack>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void preorder(Node *root)
{
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *node = st.top();
        st.pop();
        cout << node->data << " ";
        if (node->right)
            st.push(node->right);
        if (node->left)
            st.push(node->left);
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
    preorder(root);

    // output: 1 2 4 8 5 3 6 7 9
}