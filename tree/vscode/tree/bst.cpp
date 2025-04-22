#include<iostream>
#include<vector>
using namespace std;

class TreeNode {
public:
     int data = 0;
     TreeNode *left = NULL;
     TreeNode *right = NULL;

     TreeNode(int val){
       this -> data = data;
    }
};

int min(TreeNode *node)
{
    TreeNode *curr = node;
    while (curr->left != NULL)
        curr = curr->left;

    return curr->data;
}

int max(TreeNode *node)
{
    TreeNode *curr = node;
    while (curr->right != NULL)
    {
        curr = curr->right;
    }
    return curr->data;
}

int sum(TreeNode *node)
{
    if (node == nullptr)
    {
        return 0;
    }

    int ls = sum(node->left);
    int rs = sum(node->right);

    return ls + rs + node->data;
}

int size(TreeNode *node)
{

    if (node == NULL)
        return 0;

    int tsum = size(node->left);
    int ssum = size(node->right);

    return tsum + ssum + 1;
}

bool find(TreeNode *node, int data)
{
    while (node != NULL)
    {
        if (node->data == data)
        {
            return true;
        }
        else if (node->data > data)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }
    return false;
}

vector<TreeNode *> nodeToRootPath(TreeNode *node, int data){
    vector<TreeNode *> ans;
    
    while (node != NULL)
    {
        ans.push_back(node);
        if (node->data == data)
            break;
        else if (node->data > data)
            node = node->left;
        else
            node = node->right;
    }
    return ans;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    TreeNode *LCA = NULL;
    while (root != NULL)
    {
        if (root->data < p->data && root->data < q->data)
        {
            root = root->right;
        }
        else if (root->data > p->data && root->data > q->data)
        {
            root = root->left;
        }
        else
            LCA = root;
        break;
    }
    return (LCA != NULL && find(LCA, p->data) && find(LCA, q->data)) ? LCA : NULL;
}