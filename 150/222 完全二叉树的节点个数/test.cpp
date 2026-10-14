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

string tobit(int k)
{
    string s = "";
    while (k)
    {
        if (k % 2)
            s = "1" + s;
        else
            s = "0" + s;
        k /= 2;
    }
    return s;
}

bool check(TreeNode *root, int k)
{
    string s = tobit(k);
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == '1')
        {
            if (root->right)
                root = root->right;
            else
                return false;
        }
        else
        {
            if (root->left)
                root = root->left;
            else
                return false;
        }
    }
    return true;
}

int countNodes(TreeNode *root)
{
    string s = "";
    int h = 1;
    if (!root)
        return 0;
    TreeNode *t = root;
    while (t)
    {
        if (t->left)
        {
            t = t->left;
            h++;
        }
        else
        {
            break;
        }
    }
    int low = pow(2, h - 1);
    int high = pow(2, h) - 1;
    int mid = (low + high) / 2;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (check(root, mid))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (check(root, mid))
        return mid;
    else
        return mid - 1;
}

int countNodes2(TreeNode *root)
{
    if (!root)
        return 0;
    return countNodes2(root->left) + countNodes2(root->right) + 1;
}

int countNodes1(TreeNode *root)
{
    string s = "";
    if (root)
        s += "1";
    else
        return 0;
    while (root)
    {
        if (root->right)
        {
            s += "1";
            root = root->right;
        }
        else if (root->left)
        {
            s += "0";
            root = root->left;
        }
        else
        {
            break;
        }
    }
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
            sum += pow(2, s.length() - 1 - i);
    }
    return sum;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    //root->left->left = new TreeNode(4);
    //root->left->right = new TreeNode(5);
    //root->right->left=new TreeNode(6);

    cout << countNodes(root);
    cout << 1;
    return 0;
}
