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

int findKthLargest(vector<int> &nums, int k)
{
    make_heap(nums.begin(), nums.end());
    int res = 0;
    int n = nums.size();
    for (int i = 0; i < k; i++)
    {
        pop_heap(nums.begin(), nums.end());
        res = nums[n - 1];
        nums.pop_back();
        n--;
    }
    return res;
}

int main()
{
    int arr[6] = {3, 2, 1, 5, 6, 4};
    vector<int> vec;
    for (int i = 0; i < 6; i++)
    {
        vec.push_back(arr[i]);
    }
    cout << findKthLargest(vec, 2);
    // cout << 1;
    return 0;
}
