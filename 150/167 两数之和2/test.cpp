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
            res.push_back(it->second+1);
            res.push_back(i+1);
            break;
        }
    }
    return res;
}

int main()
{
    vector<string> strs;
    vector<int> nums;
    string arr[6] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    for (int i = 0; i < 6; i++)
    {
        strs.push_back(arr[i]);
    }
    int nrr[6] = {100,4,200,1,3,2};
    for (int i = 0; i < 6; i++)
    {
        nums.push_back(nrr[i]);
    }
    vector<int> res = twoSum(nums,4);
    return 0;
}
