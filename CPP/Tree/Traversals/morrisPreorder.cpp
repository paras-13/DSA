// Morris Preorder traversal
#include <iostream>
#include <vector>
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

vector<int> morrisPreorder(TreeNode *root)
{
    vector<int> preorder;
    TreeNode *node = root;
    while (node)
    {
        if (!node->left)
        {
            preorder.push_back(node->val);
            node = node->right;
        }
        else
        {
            TreeNode *temp = node->left;
            while (temp->right && temp->right != node)
                temp = temp->right;

            if (!temp->right)
            {
                temp->right = node;
                preorder.push_back(node->val);
                node = node->left;
            }
            else
            {
                temp->right = NULL;
                node = node->right;
            }
        }
    }
    return preorder;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    vector<int> preorder = morrisPreorder(root);
    cout << "Morris Preorder traversal: ";
    for (int it : preorder)
        cout << it << " ";
}