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

void preorder(TreeNode *root, vector<int> &arr)
{
    if (!root)
        return;
    preorder(root->left, arr);
    arr.push_back(root->val);
    preorder(root->right, arr);
}

bool isValidBST(TreeNode *root)
{
    bool b = true;
    vector<int> arr;
    preorder(root, arr);
    for (int i = 1; i < arr.size(); i++)
    {
        b = arr[i - 1] < arr[i];
        if (!b)
            break;
    }
    return b;
}

int main()
{
    // 5,4,6,null,null,3,7
    //      5
    //   4      6
    //        3   7
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);
    // root->right->right = new TreeNode(6);
    cout << isValidBST(root);
    cout << 1;

    return 0;
}
