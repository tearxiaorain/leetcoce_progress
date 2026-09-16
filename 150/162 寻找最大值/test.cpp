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

int find(vector<int>& nums,int l,int r)
{
    int mid=(l+r)/2;
    if(nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1])
        return mid;
    else if(nums[mid]<nums[mid+1])
        return find(nums,mid+1,r);
    else return find(nums,l,mid);
}

int findPeakElement(vector<int>& nums) {
    int n=nums.size();
    if(n==1)
        return 0;
    vector<int> num;
    num.push_back(INT_MIN);
    for(int i=0;i<n;i++)
    {
        num.push_back(nums[i]);
    }
    num.push_back(INT_MIN);
    return find(num,1,n)-1;
}

int main()
{
    int arr[7] = {1,2,1,3,5,6,4};
    vector<int> a;
    for (int i = 0; i < 7; i++)
    {
        a.push_back(arr[i]);
    }
    cout << findPeakElement(a);

    // cout << 1;
    return 0;
}
