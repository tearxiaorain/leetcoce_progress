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

bool isSymmetric(TreeNode* root)
{
    queue<TreeNode*> q;
    q.push(root);
    int count=1;
    while(!q.empty())
    {
        vector<TreeNode*> vec;
        int k=count;
        for(int i=0;i<count;i++)
        {
            vec.push_back(q.front());
            if(q.front())
            {
                q.push(q.front()->left);
                q.push(q.front()->right);
                k+=2;
            }
            q.pop();
            k--;
        }
        int le=0;
        int ri=count-1;
        while(le<ri)
        {
            if(!vec[le]&&!vec[ri])
                ;
            else if(!vec[le]||!vec[ri])
                return false;
            else
            {
                if(vec[le]->val!=vec[ri]->val)
                    return false;
            }
            le++;
            ri--;
        }
        count=k;
    }
    return true;
}

int main()
{
    TreeNode *p = new TreeNode(1); // [1,2,2,null,3,null,3]
    TreeNode *q = new TreeNode(1); // [1,null,2]

    p->left = new TreeNode(2);
    p->right = new TreeNode(2);
    //p->left->left = new TreeNode(3);
    p->left->right = new TreeNode(3);
    p->right->left = new TreeNode(3);
    //p->right->right = new TreeNode(3);
    cout << isSymmetric(p);
    return 0;
}
