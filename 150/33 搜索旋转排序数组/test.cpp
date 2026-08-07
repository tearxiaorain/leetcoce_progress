#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int search(vector<int> &nums, int target)
{
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    int mid = right / 2;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (nums[mid] > nums[left])
        {
            left = mid + 1;
        }
        else if (nums[mid] < nums[right])
        {
            right = mid - 1;
        }
        else break;
        if(nums[mid]>nums[(mid+1)%n])
            break;
    }
    int k = mid;
    if(nums[k]==target)
        return k;
    if(nums[k]<nums[(k+1)%n])
        k=(k+1)%n;
    if(nums[k]==target)
        return k;
    if (nums[k] < target)
        return -1;
    if (nums[(k + 1) % n] > target)
        return -1;
    if (target >= nums[0])
    {
        left = 0;
        right = k;
        mid = right / 2;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else break;
        }
        if (nums[mid] == target)
            return mid;
        return -1;
    }
    else if (target <= nums[n-1])
    {
        left = k+1;
        right = n-1;
        mid = right / 2;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else break;

        }
        if (nums[mid] == target)
            return mid;
        return -1;
    }
    return -1;
}

int main()
{
    int arr[9] = {6,5,6,7,0,1,2};
    int brr[9] = {1, 2, 2, 5, 1};
    int mar[3][4] = {1, 3, 5, 7, 10, 11, 16, 20, 23, 30, 34, 60};
    vector<int> n(0);
    vector<int> m(0);
    // vector<vector<int>> r(0);

    for (int i = 0; i < 2; i++)
    {
        n.push_back(arr[i]);
        // m.push_back(brr[i]);
    }
    cout << search(n, 5);
    return 0;
}
