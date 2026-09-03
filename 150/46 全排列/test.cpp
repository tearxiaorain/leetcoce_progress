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

void fun(vector<int> &nums, vector<int> &flag, vector<vector<int>> &res, vector<int> &path, int n)
{
    int f_flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (!flag[i])
        {
            f_flag++;
            flag[i] = 1;
            path.push_back(nums[i]);
            fun(nums, flag, res, path, n);
            path.pop_back();
            flag[i] = 0;
        }
    }
    if (!f_flag)
    {
        res.push_back(path);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> res;
    int n = nums.size();
    vector<int> flag(n, 0);
    vector<int> path;
    fun(nums, flag, res, path, n);
    return res;
}

int main()
{
    int arr[3] = {1, 2, 3};
    vector<int> a;
    for (int i = 0; i < 3; i++)
    {
        a.push_back(arr[i]);
    }
    vector<vector<int>> r = permute(a);
    for (int i = 0; i < r.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << r[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
