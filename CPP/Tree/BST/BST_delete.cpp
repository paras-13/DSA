#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        left = right = NULL;
    }
};
TreeNode *insertNodeInBST(TreeNode *root, int value)
{
    if (!root)
        return new TreeNode(value);
    if (root->val < value)
        root->right = insertNodeInBST(root->right, value);
    else
        root->left = insertNodeInBST(root->left, value);
    return root;
}

TreeNode *getSuccessor(TreeNode *root)
{
    TreeNode *succ = root->right;
    while (succ && succ->left)
        succ = succ->left;
    return succ;
}
TreeNode *deleteNodeInBST(TreeNode *root, int k)
{
    // base case
    if (!root)
        return root;
    if (root->val > k)
        root->left = deleteNodeInBST(root->left, k);
    else if (root->val < k)
        root->right = deleteNodeInBST(root->right, k);
    else
    {
        // if left sbtree is empty
        if (!root->left)
        {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }
        // Similarly if for a node right substree is empty
        if (!root->right)
        {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }

        // Main case where we have both children for a node
        TreeNode *succ = getSuccessor(root);
        root->val = succ->val;
        root->right = deleteNodeInBST(root->right, succ->val);
    }
    return root;
}
void levelOrderTraversal(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            cout << node->val << " ";
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        cout << endl;
    }
}
int main()
{
    int n, val, k;
    cout << "Enter number of element to enter: ";
    cin >> n;
    cout << "Enter elements: ";
    TreeNode *root = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        root = insertNodeInBST(root, val);
    }
    cout << "Level Order Traversal Before Deletion: " << endl;
    levelOrderTraversal(root);
    cout << "Element value to delete: ";
    cin >> k;
    root = deleteNodeInBST(root, k);
    cout << "Level Order Traversal After Deletion: " << endl;
    levelOrderTraversal(root);
    return 0;
}