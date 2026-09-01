#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
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

void preorder(TreeNode *root, TreeNode *p, vector<int> &s,int &flag)
{
    if (!root)
        return;
    if (root == p)
    {
        flag=1;
        return;
    }
    if(flag)
        return;
    
    s.push_back(0);
    preorder(root->left, p, s,flag);
    if(flag)
        return;
    s.pop_back();

    s.push_back(1);
    preorder(root->right, p, s,flag);
    if(flag)
        return;
    s.pop_back();
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    vector<int> sp, sq;
    //sp = sq = "";
    int flag=0;
    preorder(root, p, sp,flag);
    flag=0;
    preorder(root, q, sq,flag);
    vector<int> s;
    int np = sp.size();
    int nq = sq.size();
    int n = np;
    if (nq < np)
        n = nq;
    for (int i = 0; i < n; i++)
    {
        if (sp[i] == sq[i])
            s.push_back(sp[i]);
        else
            break;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 0)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

int main()
{
    // 3,9,20,15,7
    // 9,3,15,20,7
    // 9,15,7,20,3
    //      1
    //    2    5
    //  3  4    6
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    TreeNode *r = lowestCommonAncestor(root, root->left, root->left->right);
    cout << 1;

    return 0;
}
