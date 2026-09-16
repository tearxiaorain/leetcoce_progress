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

int reverseBits(int n) {
    vector<int> flag(32,0);
    int k=n;
    for(int i=0;i<32;i++)
    {
        if(k%2)
            flag[i]=1;
        k>>=1;
    }
    int sum=0;
    k=1;
    for(int i=31;i>=0;i--)
    {
        if(flag[i])
            sum+=k;
        k<<=1;
    }
    return sum;
}

int main()
{
    int arr[5] = {4, 1, 2, 1, 2};
    vector<int> a;
    for (int i = 0; i < 5; i++)
    {
        a.push_back(arr[i]);
    }
    cout << reverseBits(43261596);

    // cout << 1;
    return 0;
}
