#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if(n==1)
        return 0;

    int max = 0;
    int ind = 0;
    
    for(int i=0;i<n;i++)
    {
        if(prices[i]<prices[ind])
        {
            ind=i;
        }
        else
        {
            if(prices[i]-prices[ind]>max)
            {
                max = prices[i]-prices[ind];
            }
        }
    }
    return max;
}

int main()
{
    vector<int> prises;
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    for (int i = 0; i < 7; i++)
    {
        prises.push_back(arr[i]);
    }
    cout << maxProfit(prises) << endl;
    return 0;
}
