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

TreeNode *merge(vector<int> &nums, int l, int r)
{
    if (l == r)
    {
        TreeNode *root = new TreeNode(nums[r]);
        return root;
    }
    if (l == r - 1)
    {
        TreeNode *root = new TreeNode(nums[r]);
        root->left = new TreeNode(nums[l]);
        return root;
    }
    if (l == r - 2)
    {
        TreeNode *root = new TreeNode(nums[r - 1]);
        root->left = new TreeNode(nums[l]);
        root->right = new TreeNode(nums[r]);
        return root;
    }

    int mid = (l + r) / 2;
    TreeNode *tl = merge(nums, l, mid);
    TreeNode *tr = merge(nums, mid + 2, r);
    TreeNode *root = new TreeNode(nums[mid + 1]);
    root->left = tl;
    root->right = tr;
    return root;
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    TreeNode *root = merge(nums, 0, nums.size() - 1);
    return root;
}

int main()
{
    int arr[5] = {-10, -3, 0, 5, 9};
    vector<int> a;
    for (int i = 0; i < 5; i++)
    {
        a.push_back(arr[i]);
    }
    TreeNode *root = sortedArrayToBST(a);
    cout << 1;
    return 0;
}
