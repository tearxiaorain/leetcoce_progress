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

// int sumNumbers(TreeNode* root) {
//     if(!root)
//         return 0;
//     if(!root->left&&!root->right)
//         return root->val;
//     int nl,nr;
//     nl=nr=0;
//     //root->val*=10;
//     if(root->left)
//         nl=sumNumbers(root->left);
//     if(root->right)
//         nr=sumNumbers(root->right);
//     int lenl,lenr;
//     lenl=to_string(nl).length();
//     lenr=to_string(nr).length();
//     int l=max(lenl,lenr);
//     int v=root->val;
//     for(int i=0;i<l;i++)
//         v*=10;
//     return 2*v+nl+nr;
// }

vector<int> nums;

int sumNumbers(TreeNode* root) {
    if(!root)
        return 0;
    if(!root->left&&!root->right)
    {
        nums.push_back(root->val);
        return root->val;
    }
        
    int nl,nr;
    nl=nr=0;
    if(root->left)
    {
        root->left->val+=root->val*10;
        nl=sumNumbers(root->left);
    }    
    if(root->right)
    {
        root->right->val+=root->val*10;
        nr=sumNumbers(root->right);
    }
    int sum=0;
    for(int i=0;i<nums.size();i++)
    {
        sum+=nums[i];
    }
    return sum;
}

int main()
{
    TreeNode *p = new TreeNode(4); // [4,9,0,5,1]
    TreeNode *q = new TreeNode(1); // [1,2,3]

    p->left = new TreeNode(9);
    p->right = new TreeNode(0);
    p->left->left = new TreeNode(5);
    p->left->right = new TreeNode(1);
    // p->right->left = new TreeNode(13);
    // p->right->right = new TreeNode(4);
    // p->left->left->left = new TreeNode(7);
    // p->left->left->right = new TreeNode(2);
    // p->right->right->right = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    for(int i=0;i<nums.size();i++)
    {
        nums[i]=0;
    }
    cout << sumNumbers(p);
    cout<<endl;
    for(int i=0;i<nums.size();i++)
    {
        nums[i]=0;
    }
    cout << sumNumbers(q);

    return 0;
}
