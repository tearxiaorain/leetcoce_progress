#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum1(vector<int> &nums)
{
    int n = nums.size();
    map<int, vector<int>> m;
    map<vector<int>, int> r;
    vector<vector<int>> res;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        auto it = m.find(-nums[i]);
        if (it != m.end())
        {
            for (int k = 0; k < it->second.size(); k += 2)
            {
                vector<int> t;
                t.push_back(nums[i]);
                t.push_back(it->second[k]);
                t.push_back(it->second[k + 1]);
                sort(t.begin(), t.end());
                auto itt = r.find(t);
                if (itt == r.end())
                {
                    res.push_back(t);
                    r[t] = count;
                    count++;
                }
            }
        }
        for (int j = 0; j < i; j++)
        {
            auto itt = m.find(nums[i] + nums[j]);
            if (itt != m.end())
            {
                itt->second.push_back(nums[i]);
                itt->second.push_back(nums[j]);
            }
            else
            {
                vector<int> t;
                t.push_back(nums[i]);
                t.push_back(nums[j]);
                m[nums[i] + nums[j]] = t;
            }
        }
    }
    // for(int i=0;i<res.size();i++)
    // {
    //     sort(res[i].begin(),res[i].end());
    // }
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i][0] << " " << res[i][1] << " " << res[i][2] << endl;
    }
    return res;
}

vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> res;
    map<vector<int>, int> r;
    int count = 0;

    unordered_map<int, int> um1;
    unordered_map<int, int> um2;
    unordered_map<int, int> um3;
    vector<int> rnums;
    for (int i = 0; i < n; i++)
    {
        auto it1 = um1.find(nums[i]);
        if (it1 == um1.end())
        {
            um1[nums[i]] = nums[i];
            rnums.push_back(nums[i]);
        }
        else
        {
            auto it2 = um2.find(nums[i]);
            if (it2 == um2.end())
            {
                um2[nums[i]] = nums[i];
                rnums.push_back(nums[i]);
            }
            else
            {
                auto it3 = um3.find(nums[i]);
                if (it3 == um3.end())
                {
                    um3[nums[i]] = nums[i];
                    rnums.push_back(nums[i]);
                }
            }
        }
    }
    n = rnums.size();
    for (int i = 0; i < n; i++)
    {
        unordered_map<int, int> um;
        for (int j = i + 1; j < n; j++)
        {
            auto it = um.find(-rnums[i] - rnums[j]);
            if (it == um.end())
            {
                um[rnums[j]] = rnums[j];
            }
            else
            {
                vector<int> t;
                t.push_back(rnums[i]);
                t.push_back(rnums[j]);
                t.push_back(it->second);
                sort(t.begin(), t.end());
                auto itt = r.find(t);
                if (itt == r.end())
                {
                    res.push_back(t);
                    r[t] = count;
                    count++;
                }
            }
        }
    }
    return res;
}

int main()
{
    int arr[9] = {1, 2, -2, -1, -1, -4};
    int brr[9] = {1, 2, 2, 5, 1};
    vector<int> n(0);
    vector<int> m(0);
    for (int i = 0; i < 4; i++)
    {
        n.push_back(arr[i]);
        // m.push_back(brr[i]);
    }
    vector<vector<int>> res = threeSum(n);
    return 0;
}
