#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    int n=triangle.size();
    int *arr=new int[n];
    int *brr=new int[n];
    arr[0]=triangle[0][0];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            
            int l1=INT_MAX;
            int l2=INT_MAX;
            if(j-1>=0)
                l1=arr[j-1]+triangle[i][j];
            if(j<i)
                l2=arr[j]+triangle[i][j];
            brr[j]=l1;
            if(l2<l1)
                brr[j]=l2;
        }
        swap(arr,brr);
    }
    sort(arr,arr+n);
    return arr[0];
}

int main()
{
    int arr[4][4]={2,0,0,0,
                    3,4,0,0,
                    6,5,7,0,
                    4,1,8,3};
    vector<vector<int>> n;
    for(int i=1;i<5;i++)
    {
        vector<int> t;
        for(int j=0;j<i;j++)
        {
            t.push_back(arr[i-1][j]);
        }
        n.push_back(t);
    }
    cout<<minimumTotal(n);
    return 0;
}
