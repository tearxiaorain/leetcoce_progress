#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int rob(vector<int>& nums) {
    int n=nums.size();
    if(n==0)
        return 0;
    if(n==1)
        return nums[0];
    int *arr=new int[n];
    arr[0]=nums[0];
    arr[1]=nums[0];
    if(nums[1]>nums[0])
        arr[1]=nums[1];
    for(int i=2;i<n;i++)
    {
        int k1=arr[i-2]+nums[i];
        int k2=arr[i-1];
        if(k1>k2)
            arr[i]=k1;
        else
            arr[i]=k2;
    }
    return arr[n-1];
}

int main()
{   vector<int> n;
    int arr[10]={2,7,9,3,1};
    for(int i=0;i<5;i++)
    {
        n.push_back(arr[i]);
    }
    cout << rob(n);
    return 0;
}
