#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    int n=coins.size();
    //sort(coins.begin(),coins.end());
    int *arr=new int[amount+1];
    arr[0]=0;
    for(int i=0;i<n;i++)
    {
        if(coins[i]<=amount)
            arr[coins[i]]=1;
    }
    for(int i=1;i<amount+1;i++)
    {
        int flag=0;
        int min=INT_MAX;
        for(int j=n-1;j>=0;j--)
        {
            if(coins[j]<=amount)
            {
                if(i-coins[j]>=0)
                {
                    if(arr[i-coins[j]]!=-1)
                    {
                        if(min>arr[i-coins[j]]+1)
                        min=arr[i-coins[j]]+1;
                        flag++;
                    }
                }
            }
        }
        if(!flag)
            arr[i]=-1;
        else arr[i]=min;
    }
    return arr[amount];
}

int main()
{   vector<int> n;
    int arr[10]={1,2,5,3,1};
    for(int i=0;i<1;i++)
    {
        n.push_back(arr[i]);
    }
    cout << coinChange(n,1);
    return 0;
}
