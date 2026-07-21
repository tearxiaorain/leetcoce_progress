#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;
    vector<int> temp(k);
    for (int i = 0; i < k; i++)
    {
        temp[i] = nums[n - k + i];
    }
    for (int i = n - 1; i >= k; i--)
    {
        nums[i] = nums[i - k];
    }
    for (int i = 0; i < k; i++)
    {
        nums[i] = temp[i];
    }
    return;
}

int main()
{
    vector<int> nums;
    int k = 3;
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    for (int i = 0; i < 7; i++)
    {
        nums.push_back(arr[i]);
    }
    rotate(nums, k);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}