// Finding Lowest Common Ancestor
/*
    Using two methods
    1. To trace path of both nodes and then find the common node
        Time Complexity: O(n)
        Space Complexity: O(n)

    2. Using single traversal
        Time Complexity: O(n)
        Space Complexity: O(1)
*/

// Code
#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    int data;
    Node *right;
    Node *left;
    Node(int data)
    {
        this->data = data;
        right = left = NULL;
    }
};

Node *LCA(Node *root, int n1, int n2)
{
    if (!root)
        return nullptr;
    if (root->data == n1 || root->data == n2)
        return root;

    Node *left = LCA(root->left, n1, n2);
    Node *right = LCA(root->right, n1, n2);

    // Here if both left and right are not null, then the current node is the LCA
    if (left && right)
        return root;

    // else if one of the side is not null, then return that side
    return left ? left : right;
}
bool findPath(Node *root, int n, vector<int> &path)
{
    path.push_back(root->data);
    if (root->data == n)
        return true;

    if (root->left)
    {
        if (findPath(root->left, n, path))
            return true;
    }
    if (root->right)
    {
        if (findPath(root->right, n, path))
            return true;
    }
    path.pop_back();
    return false;
}
int findLCA(Node *root, int n1, int n2)
{
    // Method 1
    // We have to form two path matrices and then find the common node from both paths which is the LCA
    vector<int> path1, path2;
    findPath(root, n1, path1);
    findPath(root, n2, path2);
    if (path1.empty() || path2.empty())
    {
        return -1;
    }
    int lca;
    int i = 0, j = 0;
    while (i < path1.size() && j < path2.size())
    {
        if (path1[i] == path2[j])
            lca = path1[i];
        i++;
        j++;
    }

    // Method 2
    // Recursive approach using single traversal
    Node *Lca = LCA(root, n1, n2);
    if (!Lca)
        lca = -1;
    else
        lca = Lca->data;
    return lca;
}
int main()
{
    int n1, n2;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout << "Enter value for target node 1: ";
    cin >> n1;
    cout << "Enter value for target node 2: ";
    cin >> n2;
    int LCA = findLCA(root, n1, n2);
    if (LCA != -1)
        cout << "Lowest Common Ancestor: " << LCA << endl;
    else
        cout << "Lowest Common Ancestor not found\n";
}