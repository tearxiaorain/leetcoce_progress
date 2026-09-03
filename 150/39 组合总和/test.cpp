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

void fun(vector<int>& candidates, int target,int &sum,int c,vector<int> &path,vector<vector<int>> &res)
{
    if(sum>target)
        return;
    else if(sum==target)
    {
        res.push_back(path);
        return;
    }
    else
    {
        int n=candidates.size();
        for(int i=c;i>=0;i--)
        {
            path.push_back(candidates[i]);
            sum+=candidates[i];
            fun(candidates,target,sum,i,path,res);
            sum-=candidates[i];
            path.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    int n=candidates.size();
    sort(candidates.begin(),candidates.end());
    int sum=0;
    vector<int> path;
    fun(candidates,target,sum,n-1,path,res);
    return res;
}

int main()
{
    int nrr[6] = {2,3,5};
    vector<int> nums;
    for (int i = 0; i < 3; i++)
    {
        nums.push_back(nrr[i]);
    }
    vector<vector<int>> r = combinationSum(nums,8);
    cout << 1;
    return 0;
}
