#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    map<int,int> m;
    int n=nums.size();
    vector<int> res(0);
    int flag=0;
    for(int i=0;i<n;i++)
    {
        auto it = m.find(nums[i]);
        if(it==m.end())
        {
            m[target-nums[i]]=i;
        }
        else
        {
            flag++;
            res.push_back(i);
            res.push_back(it->second);
            break;
        }
    }
    return res;
}


int main()
{
    vector<string> strs;
    string arr[6] = {"eat","tea","tan","ate","nat","bat"};
    for (int i = 0; i < 6; i++)
    {
        strs.push_back(arr[i]);
    }
    vector<vector<string>> res = twoSum(strs);
    return 0;
}
