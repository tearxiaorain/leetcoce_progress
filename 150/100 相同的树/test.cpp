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

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == nullptr && q == nullptr)
        return true;
    if (!p || !q)
        return false;
    if (p->val == q->val)
    {
        bool r1 = isSameTree(p->left, q->left);
        bool r2 = isSameTree(p->right, q->right);
        if (r1 && r2)
            return true;
        return false;
    }
    else
        return false;
}

int main()
{
    TreeNode *p = new TreeNode(1); // [1,2]
    TreeNode *q = new TreeNode(1); // [1,null,2]

    p->left = new TreeNode(2);
    q->right = new TreeNode(2);
    // p->right->left = new TreeNode(15);
    // p->right->right = new TreeNode(7);
    cout << isSameTree(p,q);
    return 0;
}
