#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int candy(vector<int>& ratings) {
    int n=ratings.size();
    int count=n;
    vector <int> can(n,1);
    for(int i=1;i<n;i++)
    {
        int c=0;
        if(ratings[i]>ratings[i-1])
        {
            c=can[i-1]+1-can[i];
        }
        can[i]+=c;
        count+=c;
    }
    for(int i=n-2;i>=0;i--)
    {
        int c=0;
        if(ratings[i]>ratings[i+1])
        {
            if(can[i]>can[i+1])
                continue;
            c=can[i+1]+1-can[i];
        }
        can[i]+=c;
        count+=c;
    }
    return count;
}

int main()
{
    int arr[9] = {1,2,87,87,87,2,1};
    int brr[9] = {1,2,2,5,1};
    vector<int> n(0);
    vector<int> m(0);
    for (int i = 0; i < 7; i++)
    {
        n.push_back(arr[i]);
        m.push_back(brr[i]);
    }
    cout << candy(n);
    return 0;
}
