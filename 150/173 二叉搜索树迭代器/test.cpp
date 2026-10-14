#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <math.h>

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

class BSTIterator
{
public:
    vector<TreeNode *> vec;
    int c;
    int nums;

    void midorder(TreeNode *root)
    {
        if (!root)
            return;
        midorder(root->left);
        vec.push_back(root);
        midorder(root->right);
    }

    BSTIterator(TreeNode *root)
    {
        c = -1;
        vec.clear();

        midorder(root);
        nums = vec.size();
    }

    int next()
    {
        c++;
        return vec[c]->val;
    }

    bool hasNext()
    {
        if (c + 1 < nums)
            return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */