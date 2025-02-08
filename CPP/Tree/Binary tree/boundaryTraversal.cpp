// Boundary Traversal in a Binary Tree
// Done in a nticlockwise fashion
// Starting from left side then leaf nodes and then right side
// Time Complexity: O(n)
// Space Complexity: O(h), where h is the height of the tree

#include <iostream>
#include <vector>
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

bool isLeaf(Node *root)
{
    if (!root->left && !root->right)
        return true;
    return false;
}
void leftTraversal(Node *root, vector<int> &res)
{
    if (!root || isLeaf(root))
        return;
    res.push_back(root->data);
    if (root->left)
        leftTraversal(root->left, res);
    else
        leftTraversal(root->right, res);
}
void leafTraversal(Node *root, vector<int> &res)
{
    if (!root)
        return;
    if (isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }
    leafTraversal(root->left, res);
    leafTraversal(root->right, res);
}
void rightTraversal(Node *root, vector<int> &res)
{
    if (!root || isLeaf(root))
        return;
    if (root->right)
        rightTraversal(root->right, res);
    else
        rightTraversal(root->left, res);
    res.push_back(root->data);
}
vector<int> boundaryTraversal(Node *root)
{
    vector<int> res;
    if (!root)
        return res;
    if (!isLeaf(root))
        res.push_back(root->data);
    leftTraversal(root->left, res);
    leafTraversal(root, res);
    rightTraversal(root->right, res);
    return res;
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
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(13);
    root->right->right->left = new Node(14);
    root->right->right->right = new Node(15);
    vector<int> res = boundaryTraversal(root);
    if (res.empty())
        cout << "Empty tree\n";
    else
        for (int it : res)
            cout << it << " ";
}