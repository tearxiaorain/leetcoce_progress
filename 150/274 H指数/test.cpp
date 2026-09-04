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

int hIndex(vector<int>& citations) {
    sort(citations.begin(),citations.end());
    int n=citations.size();
    int t=n;
    while(t>=0)
    {
        int flag=0;
        for(int i=0;i<t;i++)
        {
            if(citations[n-t+i]<t)
            {
                flag=1;
                break;
            }
        }
        if(flag)
        {
            t--;
        }
        else return t;
    }    
    return t;    
}

int main()
{
    int arr[5] = {1,3,1,1,5};
    vector<int> a;
    for (int i = 0; i < 3; i++)
    {
        a.push_back(arr[i]);
    }
    cout << hIndex(a);
    // cout << 1;
    return 0;
}
