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

bool hasPathSum(TreeNode* root, int targetSum) {
    if(!root)
        return false;
    if(!root->left&&!root->right)
    {
        if(targetSum==root->val)
            return true;
        return false;
    }
    int b1,b2;
    b1=b2=false;
    if(root->left)
        b1=hasPathSum(root->left,targetSum-root->val);
    if(root->right)
        b2=hasPathSum(root->right,targetSum-root->val);
    return b1||b2;
}


int main()
{
    TreeNode *p = new TreeNode(5); // [5,4,8,11,null,13,4,7,2,null,null,null,1]
    /*
                    5
                4       8
            11        13  4
        7       2           1
    
    
    */
    //TreeNode *q = new TreeNode(1); // [1,null,2]

    p->left = new TreeNode(4);
    p->right = new TreeNode(8);
    p->left->left = new TreeNode(11);
    //p->left->right = new TreeNode(3);
    p->right->left = new TreeNode(13);
    p->right->right = new TreeNode(4);
    p->left->left->left = new TreeNode(7);
    p->left->left->right = new TreeNode(2);
    p->right->right->right = new TreeNode(1);

    cout << hasPathSum(p,22);
    return 0;
}
