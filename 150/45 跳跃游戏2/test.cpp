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

int jump(vector<int> &nums)
{
    int n = nums.size();
    vector<int> flag(n, -1);
    flag[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j <= i + nums[i] && j < n; j++)
        {
            if (flag[j] == -1)
                flag[j] = flag[i] + 1;
            else
            {
            }
        }
    }
    return flag[n - 1];
}

int main()
{
    int arr[5] = {2,3,1,1,4};
    vector<int> a;
    for (int i = 0; i < 5; i++)
    {
        a.push_back(arr[i]);
    }
    cout << jump(a);
    // cout << 1;
    return 0;
}
