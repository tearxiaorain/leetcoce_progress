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

void preorder(TreeNode *root, vector<TreeNode *> &arr)
{
    if (!root)
        return;
    arr.push_back(root);
    preorder(root->left, arr);
    preorder(root->right, arr);
}

void flatten(TreeNode *root)
{
    if(!root)
        return;
    vector<TreeNode *> arr;
    preorder(root, arr);
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        arr[i]->left = nullptr;
        arr[i]->right = arr[i + 1];
    }
    arr[n - 1]->left = nullptr;
    arr[n - 1]->right = nullptr;
}

int main()
{
    // 3,9,20,15,7
    // 9,3,15,20,7
    // 9,15,7,20,3
    //      1
    //    2    3
    //  4  5    7
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    flatten(root);
    cout << 1;

    return 0;
}
