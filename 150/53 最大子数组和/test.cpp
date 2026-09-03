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

int maxSubArray(vector<int>& nums) {
    int ns=nums.size();
    vector<int>num;
    int t=0;
    int m=INT_MIN;
    for(int i=0;i<ns;i++)
    {
        if(nums[i]>0)
        {
            if(t!=0)
                num.push_back(t);
            num.push_back(nums[i]);
            t=0;
        }
        else
        {
            t+=nums[i];
            if(m<nums[i])
                m=nums[i];
        }
    }
    num.push_back(t);

    int n=num.size();
    if(n==1)
    {
        if(num[0]<=0)
            return m;
    }
    vector<int> sums(n,0);
    sums[0]=num[0];
    for(int i=1;i<n;i++)
    {
        sums[i]=sums[i-1]+num[i];
    }
    int max_sum=INT_MIN;
    int l,r;
    l=r=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(max_sum<sums[j]-sums[i]+num[i])
            {
                max_sum=sums[j]-sums[i]+num[i];
                l=i;r=j;
            }
        }
    }
    return max_sum;
}

int main()
{
    int nrr[9] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> nums;
    for (int i = 0; i < 9; i++)
    {
        nums.push_back(nrr[i]);
    }
    cout<< maxSubArray(nums);
    cout << 1;
    return 0;
}
