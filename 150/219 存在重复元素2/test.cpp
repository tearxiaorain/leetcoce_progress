#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    map<int, int> m;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        auto it = m.find(nums[i]);
        if (it == m.end())
        {
            m[nums[i]] = i;
        }
        else
        {
            if (i - it->second > k)
            {
                m[nums[i]] = i;
            }
            else
                return true;
        }
    }
    return false;
}

int main()
{
    vector<string> strs;
    vector<int> nums;
    string arr[6] = {"eat","tea","tan","ate","nat","bat"};
    for (int i = 0; i < 6; i++)
    {
        strs.push_back(arr[i]);
    }
    int nrr[6] = {1,2,3,1,2,3};
    for (int i = 0; i < 6; i++)
    {
        nums.push_back(nrr[i]);
    }
    cout << containsNearbyDuplicate(nums,2);
    return 0;
}
