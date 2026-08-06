#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int ind=0;
    int n=gas.size();
    int count=0;
    int t=gas[0];
    for(int i=0;i<n;i++)
    {
        t-=cost[i%n];
        count-=cost[i%n];
        if(t<0)
        {
            t=0;
            ind=(i+1)%n;
        }
        count+=gas[(i+1)%n];
        t+=gas[(i+1)%n];
    }
    if(count>=0)
        return ind;
    return -1;
}

void fun(vector<int>& gas, vector<int>& cost, int k)
{
    int n=gas.size();
    int count=0;
    for(int i=k;i<k+n;i++)
    {   
        count+=gas[i%n];
        cout<<count<<" ";
        count-=cost[i%n];
        cout<<count<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[9] = {3,1,1,3,4};
    int brr[9] = {1,2,2,5,1};
    vector<int> n(0);
    vector<int> m(0);
    for (int i = 0; i < 3; i++)
    {
        n.push_back(arr[i]);
        m.push_back(brr[i]);
    }
    for(int i=0;i<3;i++)
    {
        fun(n,m,i);
    }
    cout << canCompleteCircuit(n,m);
    return 0;
}
