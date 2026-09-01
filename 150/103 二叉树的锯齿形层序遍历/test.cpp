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

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    queue<TreeNode *> q;
    q.push(root);
    int factor = 1;
    while (!q.empty())
    {
        factor = 1 - factor;
        int n = q.size();
        vector<int> r;
        for (int i = 0; i < n; i++)
        {
            TreeNode *t = q.front();
            q.pop();
            if (t)
            {
                q.push(t->left);
                q.push(t->right);
                r.push_back(t->val);
            }
        }
        if (r.size())
        {
            if (factor)
            {
                int nn = r.size();
                vector<int> rr;
                for (int i = nn - 1; i >= 0; i--)
                {
                    rr.push_back(r[i]);
                }
                res.push_back(rr);
            }
            else
                res.push_back(r);
        }
    }
    return res;
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
    vector<vector<int>> res = zigzagLevelOrder(root);
    cout << 1;

    return 0;
}
