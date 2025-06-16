// Binary Tree Left Side View

#include <iostream>
#include <vector>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *right;
    TreeNode *left;
    TreeNode(int val)
    {
        this->val = val;
        right = left = NULL;
    }
};

void leftView(TreeNode *root, vector<int> &res, int level)
{
    if (level == res.size())
        res.push_back(root->val);
    if (root->left)
        leftView(root->left, res, level + 1);
    if (root->right)
        leftView(root->right, res, level + 1);
}
vector<int> leftSideView(TreeNode *root)
{
    if (!root)
        return {};
    vector<int> res;
    leftView(root, res, 0);
    return res;
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    vector<int> res = leftSideView(root);
    if (res.empty())
        cout << "No left view possible" << endl;
    else
    {
        cout << "Left view: ";
        for (int it : res)
            cout << it << " ";
    }
    return 0;
}