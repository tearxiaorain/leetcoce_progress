#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n=prices.size();
    int count=0;
    int ind=0;
    int flag=0;
    for(int i=1;i<n;i++)
    {
        if(!flag)
        {
            if(prices[i]<prices[i-1])
            {
                flag=1;
                ind=i;
            }
            else
            {
                count+=(prices[i]-prices[i-1]);
            }
        }
        else
        {
            if(prices[i]>prices[ind])
            {
                count+=(prices[i]-prices[ind]);
                flag=0;
            }
            else
            {
                ind=i;
            }
        }
    }
    return count;
}

int main()
{
    int arr[9] = {3,2,6,5,0,3, 5, 6};
    vector<int> n(0);
    for (int i = 0; i < 6; i++)
    {
        n.push_back(arr[i]);
    }
    cout << maxProfit(n);
    return 0;
}
