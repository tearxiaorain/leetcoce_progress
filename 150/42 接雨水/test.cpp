#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int trap(vector<int>& height) {
    vector <pair<int,int>> arr(0);
    int n=height.size();
    for(int i=0;i<n;i++)
    {
        pair<int,int> temp;
        temp.first=height[i];
        temp.second=i;
        arr.push_back(temp);
    }
    sort(arr.begin(),arr.end());
    int n1=n-1;
    int n2=n-1;
    int count=0;
    int d1=arr[n2].second;
    int d2=arr[n2].second;
    while(n1>=0)
    {
        if(arr[n1].first!=arr[n2].first)
        {   

            int len=n-n1-1;
            int Len=d2-d1+1;
            int h1=arr[n2].first;
            int h2=arr[n1].first;
            count+=(Len-len)*(h1-h2);
            n2=n1;
        }
        if(d1>arr[n1].second)
        {
            d1=arr[n1].second;
        }
        if(d2<arr[n1].second)
        {
            d2=arr[n1].second;
        }
        n1--;
    }
    return count;
}

int main()
{
    int arr[12]={0,1,0,2,1,0,1,3,2,1,2,1};
    vector <int>n;
    for(int i=0;i<12;i++)
    {
        n.push_back(arr[i]);
    }
    int brr[6]={4,2,0,3,2,5};
    /*                      1
        1                   1   4=6-2
        1           1       1   3=6-3
        1   1       1   1   1   1=6-5
        1   1       1   1   1   1=6-5
    */
    vector <int>m;
    for(int i=0;i<6;i++)
    {
        m.push_back(brr[i]);
    }
    cout<<trap(n);
    cout<<trap(m);

    return 0;
}
