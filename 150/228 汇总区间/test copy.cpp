#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

// 先对起始端点排序
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n=intervals.size();
    vector<vector<int>> res(0);
    sort(intervals.begin(),intervals.end());
    int ind1=intervals[0][0];
    int ind2=intervals[0][1];
    for(int i=1;i<n;i++)
    {
        int ind3=intervals[i][0];
        int ind4=intervals[i][1];

        if(ind3>ind2)
        {
            res.push_back({ind1,ind2});
            ind1=ind3;
            ind2=ind4;
        }
        else
        {
            if(ind4>ind2)
                ind2=ind4;
        }
    }
    res.push_back({ind1,ind2});
    return res;
}

int main()
{
    vector<string> strs;
    vector<int> nums;
    string arr[6] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    for (int i = 0; i < 6; i++)
    {
        strs.push_back(arr[i]);
    }
    int nrr[7] = {0,2,3,4,6,8,9};
    for (int i = 0; i < 7; i++)
    {
        nums.push_back(nrr[i]);
    }
    vector<vector<int>> intervals;
    int n[8] = {1,3,2,6,8,10,15,18};
    for(int i=0;i<8;i+=2)
    {
        intervals.push_back({n[i],n[i+1]});
    }

    vector<vector<int>> res = merge(intervals);
    return 0;
}
