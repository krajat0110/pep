#include <iostream>
#include <vector>
#include <list>
using namespace std;

class TreeNode
{
public:
    int val = 0;
    TreeNode *left = NULL;
    TreeNode *right = NULL;

    TreeNode(int val)
    {
        this->val = val;
    }
};

int size(TreeNode *root)
{
    return root == NULL ? 0 : size(root->left) + size(root->right) + 1;
}

int height(TreeNode *root)
{
    return root == NULL ? -1 : max(height(root->left), height(root->right)) + 1;
}

int diameterTree(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int rd = diameterTree(root->right);
    int ld = diameterTree(root->left);

    int rh = height(root -> right);
    int lh = height(root -> left);

    return max(max(rd , ld) , rh + lh + 2);
}

int main(){

}