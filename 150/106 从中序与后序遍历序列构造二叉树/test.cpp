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

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    if (!postorder.size())
        return nullptr;
    int l = postorder.size();
    TreeNode *root = new TreeNode(postorder[l - 1]);
    int vr = postorder[l - 1];
    vector<int> lpost;
    vector<int> lin;
    vector<int> rpost;
    vector<int> rin;
    int root_index = 0;
    for (int i = 0; i < inorder.size(); i++)
    {
        if (inorder[i] == vr)
        {
            root_index = i;
            break;
        }
        lpost.push_back(postorder[i]);
        lin.push_back(inorder[i]);
    }
    for (int i = root_index + 1; i < inorder.size(); i++)
    {
        rpost.push_back(postorder[i - 1]);
        rin.push_back(inorder[i]);
    }
    root->left = buildTree(lin, lpost);
    root->right = buildTree(rin, rpost);
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
