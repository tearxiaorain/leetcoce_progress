#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;


vector<int> productExceptSelf(vector<int>& nums) {
    int n=nums.size();
    vector <int> res(n,1);
    vector <int> m1(n,1);
    vector <int> m2(n,1);
    m1[0]=nums[0];
    m2[n-1]=nums[n-1];

    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         if(i!=j)
    //             res[j]*=nums[i];
    //     }
    // }

    for(int i=1;i<n;i++)
    {
        m1[i]=m1[i-1]*nums[i];
        m2[n-i-1]=m2[n-i]*nums[n-i-1];
    }
    res[0]=m2[1];
    res[n-1]=m1[n-2];
    for(int i=1;i<n-1;i++)
    {
        res[i]=m1[i-1]*m2[i+1];
    }
    return res;
}


int main()
{
    int arr[9] = {1,2,3,4,0,3, 5, 6};
    vector<int> n(0);
    for (int i = 0; i < 4; i++)
    {
        n.push_back(arr[i]);
    }
    vector<int> r = productExceptSelf(n);
    return 0;
}
