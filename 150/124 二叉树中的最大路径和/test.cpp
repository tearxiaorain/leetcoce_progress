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

int maxPath(TreeNode* root,int& outl,int& outr) {
    if(!root)
        return -2000;
    int l=maxPath(root->left,outl,outr);
    int r=maxPath(root->right,outl,outr);
    int arr[3];
    outl=l;
    outr=r;
    arr[0]=root->val;
    arr[1]=l+root->val;
    arr[2]=r+root->val;
    sort(arr,arr+3);
    return arr[2];
}

void midorder(TreeNode* root,int& max)
{
    if(!root)
        return;
    midorder(root->left,max);

    int l,r;
    int m1=maxPath(root,l,r);
    int m2=l+r+root->val;
    if(m1>max)
        max=m1;
    if(m2>max)
        max=m2;

    midorder(root->right,max);
}

int maxPathSum(TreeNode* root) {
    int max=INT_MIN;
    midorder(root,max);
    return max;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    //root->left->left = new TreeNode(4);
    //root->left->right = new TreeNode(5);
    //root->right->left=new TreeNode(15);
    //root->right->right=new TreeNode(7);


    cout << maxPathSum(root);
    cout << 1;
    return 0;
}