#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int left=0;
    int right=nums.size()-1;
    int mid=right/2;
    if(nums[left]>target)
        return 0;
    if(nums[right]<target)
        return right+1;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(nums[mid]>target)
        {
            right=mid-1;
        }
        else if(nums[mid]<target)
        {
            left=mid+1;
        }
        else
            break;
    }
    if(nums[mid]==target)
        return mid;
    if(nums[mid]<target&&nums[mid+1]>=target)
        return mid+1;
    return mid;
}




int main()
{
    int arr[9] = {1,3,5,6, -1, -4};
    int brr[9] = {1, 2, 2, 5, 1};
    vector<int> n(0);
    vector<int> m(0);
    for (int i = 0; i < 2; i++)
    {
        n.push_back(arr[i]);
        // m.push_back(brr[i]);
    }
    cout<< searchInsert(n,2);
    return 0;
}
