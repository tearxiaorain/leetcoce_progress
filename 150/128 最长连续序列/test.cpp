#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    int n = nums.size();
    vector<int> counts(n, 0);
    int count = 0;
    int max = 0;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        auto it = m.find(nums[i]);
        if (it == m.end())
        {
            m[nums[i]] = i;
        }
    }
    for (auto it0 = m.begin();it0!=m.end();it0++)
    {
        auto it = m.find(it0->first - 1);
        if (it == m.end())
        {
            count = 1;
            int j = it0->first;
            while (1)
            {
                it = m.find(j + 1);
                if (it == m.end())
                    break;
                count++;
                j++;
            }
            if (count > max)
                max = count;
            count = 0;
        }
    }
    return max;
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
    cout << longestConsecutive(nums);
    return 0;
}
