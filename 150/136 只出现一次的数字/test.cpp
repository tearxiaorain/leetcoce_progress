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

int singleNumber(vector<int>& nums) {
    int n=nums.size();
    int k=nums[0];
    for(int i=1;i<n;i++)
    {
        k=k^nums[i];
    }
    return k;
}

int main()
{
    int arr[5]={4,1,2,1,2};
    vector<int> a;
    for(int i=0;i<5;i++)
    {
        a.push_back(arr[i]);
    }
    cout<<singleNumber(a);

    // cout << 1;
    return 0;
}
