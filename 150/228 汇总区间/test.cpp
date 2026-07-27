#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

vector<string> summaryRanges(vector<int> &nums)
{
    int n = nums.size();
    vector<string> res(0);
    string s = "";
    if (!n)
        return res;
    s += to_string(nums[0]);
    int ind = 0;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] != nums[i - 1] + 1)
        {
            if (i - 1 != ind)
            {
                s += "->";
                s += to_string(nums[i - 1]);
                res.push_back(s);
                s = "";
                s += to_string(nums[i]);
            }
            else
            {
                res.push_back(s);
                s = "";
                s += to_string(nums[i]);
            }
            ind = i;
        }
    }
    if (n - 1 != ind)
    {
        s += "->";
        s += to_string(nums[n - 1]);
        res.push_back(s);
    }
    else
    {
        res.push_back(s);
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
    int nrr[7] = {0,2,3,4,6,8,9};
    for (int i = 0; i < 7; i++)
    {
        nums.push_back(nrr[i]);
    }
    vector<string> res = summaryRanges(nums);
    return 0;
}
