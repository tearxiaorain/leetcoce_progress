#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* invertTree(TreeNode *p)
{
    if (p == nullptr)
        return p;
    TreeNode *t1=invertTree(p->left);
    TreeNode *t2=invertTree(p->right);
    p->left=t2;
    p->right=t1;
    return p;
}

int main()
{
    TreeNode *p = new TreeNode(4); // [4,2,7,1,3,6,9]
    TreeNode *q; // [1,null,2]

    p->left = new TreeNode(2);
    p->right = new TreeNode(7);
    p->left->left = new TreeNode(1);
    p->left->right = new TreeNode(3);
    p->right->left = new TreeNode(6);
    p->right->right = new TreeNode(9);
    q = invertTree(p);
    return 0;
}
