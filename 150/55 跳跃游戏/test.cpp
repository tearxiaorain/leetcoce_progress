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

bool canJump(vector<int> &nums)
{
    int n = nums.size();
    vector<bool> flag(n, false);
    flag[0] = true;
    for (int i = 0; i < n; i++)
    {
        if (flag[i])
        {
            if (i + nums[i] >= n - 1)
                return true;
            for (int j = i; j <= i + nums[i]; j++)
            {
                flag[j] = true;
            }
        }
    }
    return flag[n - 1];
}

int main()
{
    int arr[5] = {3, 2, 1, 0, 4};
    vector<int> a;
    for (int i = 0; i < 5; i++)
    {
        a.push_back(arr[i]);
    }
    cout << canJump(a);
    // cout << 1;
    return 0;
}
