// Morris Traversal Inorder
// Morris traversal targets traversal in an interative manner using constant space

// We use threaded binary tree concept here
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

vector<int> morrisInorder(TreeNode *root)
{
    vector<int> inorder;
    TreeNode *node = root;
    while (node)
    {
        if (node->left == NULL)
        {
            inorder.push_back(node->val);
            node = node->right;
        }
        else
        {
            TreeNode *temp = node->left;
            while (temp->right && temp->right != node)
                temp = temp->right;
            if (temp->right == NULL)
            {
                temp->right = node;
                node = node->left;
            }
            else
            {
                temp->right = NULL;
                inorder.push_back(node->val);
                node = node->right;
            }
        }
    }
    return inorder;
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

    vector<int> res = morrisInorder(root);
    cout << "Morris Inorder traversal: ";
    for (int it : res)
        cout << it << " ";
    return 0;
}