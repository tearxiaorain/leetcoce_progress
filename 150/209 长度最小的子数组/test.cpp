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

int minSubArrayLen1(int target, vector<int>& nums) {
    vector<int> sum;
    int n=nums.size();
    if(n==0)
        return 0;
    sum.push_back(nums[0]);
    for(int i=1;i<n;i++)
    {
        sum.push_back(sum[i-1]+nums[i]);
    }
    if(sum[n-1]<target)
        return 0;
    int l=0;
    int r=n-1;
    while(sum[r]-sum[l]+nums[l]>=target)
    {
        int s=sum[r]-sum[l]+nums[l];
        if(s-nums[l]>=target&&s-nums[r]<target)
        {
            l++;
        }
        else if(s-nums[l]<target&&s-nums[r]>=target)
        {
            r--;
        }
        else if(s-nums[l]<target&&s-nums[r]<target)
        {
            break;
        }
        else
        {
            if(nums[l]>nums[r])
                r--;
            else    l++;
        }
    }
    return r-l+1;
}

int minSubArrayLen2(int target, vector<int>& nums) {
    vector<int> sum;
    int n=nums.size();
    if(n==0)
        return 0;
    sum.push_back(nums[0]);
    for(int i=1;i<n;i++)
    {
        sum.push_back(sum[i-1]+nums[i]);
    }
    if(sum[n-1]<target)
        return 0;
    
    int min=INT_MAX;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int s=sum[j]-sum[i]+nums[i];
            if(s>=target)
            {
                if(min>j-i+1)
                {
                    min=j-i+1;
                    break;
                }
                    
            }
        }
    }
    return min;
}

int minSubArrayLen(int target, vector<int>& nums) {
    vector<int> sum;
    int n=nums.size();
    if(n==0)
        return 0;
    sum.push_back(nums[0]);
    for(int i=1;i<n;i++)
    {
        sum.push_back(sum[i-1]+nums[i]);
    }
    if(sum[n-1]<target)
        return 0;
    
    int min=INT_MAX;
    for(int i=0;i<n;i++)
    {
        // 二分查第一个大于target的前缀和
        int l=i;
        int r=n-1;
        int mid=(l+r)/2;
        if(sum[r]-sum[l]+nums[l]<target)
            continue;
        while(l<r)
        {
            mid=(l+r)/2;
            int s=sum[mid]-sum[i]+nums[i];
            if(s>=target)
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        // 最后l为所查
        if(min>l-i+1)
            min=l-i+1;
    }
    return min;
}

int main()
{
    int nrr[15] = {4,4,1000,1,1,1,5};  // 1008 , 3
    // 
    vector<int> nums;
    for (int i = 0; i < 7; i++)
    {
        nums.push_back(nrr[i]);
    }
    cout<< minSubArrayLen(1008,nums);
    //cout << 1;
    return 0;
}
