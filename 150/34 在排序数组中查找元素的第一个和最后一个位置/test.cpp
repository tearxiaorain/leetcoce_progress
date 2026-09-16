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

int find(vector<int> &nums, int l, int r, int t)
{
    int mid = (l + r) / 2;
    if (l == r)
    {
        if (nums[l] != t)
            return -1;
    }
    if (l > r)
        return -1;
    if (nums[mid] == t)
        return mid;
    else if (nums[mid] > t)
        return find(nums, l, mid, t);
    else
        return find(nums, mid + 1, r, t);
}

int findbegin(vector<int> &nums, int l, int r, int t)
{
    int mid = (l + r) / 2;
    if (l >= r)
        return r;
    if (nums[mid] < t)
        return findbegin(nums, mid + 1, r, t);
    else
        return findbegin(nums, l, mid, t);
}

int findend(vector<int> &nums, int l, int r, int t)
{
    int mid = (l + r) / 2;
    if (l >= r)
        return l;
    if (nums[mid] > t)
        return findend(nums, l, mid, t);
    else
        return findend(nums, mid + 1, r, t);
}

vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> res(2, -1);
    int n = nums.size();
    if (n == 0)
        return res;
    int ind = find(nums, 0, n - 1, target);
    if (ind == -1)
        return res;
    else
    {
        int be = findbegin(nums, 0, ind, target);
        int en = findend(nums, ind, n - 1, target);
        if (nums[en] != target)
            en--;
        res[0] = be;
        res[1] = en;
    }
    return res;
}

int main()
{
    int arr[7] = {5, 7, 7, 8, 8, 10};
    vector<int> a;
    for (int i = 0; i < 6; i++)
    {
        a.push_back(arr[i]);
    }
    cout << searchRange(a, 8)[0] << " " << searchRange(a, 8)[1];

    // cout << 1;
    return 0;
}
