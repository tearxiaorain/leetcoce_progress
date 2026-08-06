#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int lengthOfLIS(vector<int>& nums)
{
    int n=nums.size();
    int *arr=new int[n];
    int *len=new int[n];
    arr[0]=nums[0];
    len[0]=1;
    for(int i=1;i<n;i++)
    {
        int flag=0;
        int ind;
        int max=0;
        for(int j=i-1;j>=0;j--)
        {
            if(nums[i]>arr[j])
            {
                // arr[i]=nums[i];
                // len[i]=len[j]+1;
                flag++;
                if(max<len[j])
                {
                    max=len[j];
                    ind=j;
                }
            }
        }
        if(!flag)
        {
            arr[i]=nums[i];
            len[i]=1;
        }
        else
        {
            arr[i]=nums[i];
            len[i]=len[ind]+1;
        }
    }
    int max_l=0;
    for(int i=0;i<n;i++)
    {
        if(max_l<len[i])
            max_l=len[i];
    }
    return max_l;
}

int main()
{
    int arr[9] = {1,3,6,7,9,4,10,5,6};
    vector<int> n(0);
    for (int i = 0; i < 9; i++)
    {
        n.push_back(arr[i]);
    }
    cout << lengthOfLIS(n);
    return 0;
}
