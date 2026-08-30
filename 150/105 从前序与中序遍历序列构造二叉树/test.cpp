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

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    if (!preorder.size())
        return nullptr;
    TreeNode *root = new TreeNode(preorder[0]);
    int vr = preorder[0];
    vector<int> lpre;
    vector<int> lin;
    vector<int> rpre;
    vector<int> rin;
    int root_index = 0;
    for (int i = 0; i < inorder.size(); i++)
    {
        if (inorder[i] == vr)
        {
            root_index = i;
            break;
        }
        lpre.push_back(preorder[i + 1]);
        lin.push_back(inorder[i]);
    }
    for (int i = root_index + 1; i < inorder.size(); i++)
    {
        rpre.push_back(preorder[i]);
        rin.push_back(inorder[i]);
    }
    root->left = buildTree(lpre, lin);
    root->right = buildTree(rpre, rin);
    return root;
}

int main()
{
    // 3,9,20,15,7
    // 9,3,15,20,7
    //      3
    //    9   20
    //       15 7
    int arr[5] = {3, 9, 20, 15, 7};
    int brr[5] = {9, 3, 15, 20, 7};
    vector<int> rpre;
    vector<int> rin;
    for (int i = 0; i < 5; i++)
    {
        rpre.push_back(arr[i]);
        rin.push_back(brr[i]);
    }
    TreeNode *root = buildTree(rpre, rin);
    cout << 1;

    return 0;
}
