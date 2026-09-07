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

class val_pair
{
public:
    int val;
    pair<int,int> p;
    val_pair():val(0),p(0,0){};
    val_pair(int v):val(v),p(0,0){};
    val_pair(int v,int p1,int p2):val(v),p(p1,p2){};
    bool operator()(const val_pair& a, const val_pair& b) {
        return a.val > b.val;
    }
};

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    priority_queue <val_pair,vector<val_pair>,val_pair> pq;
    int n1=nums1.size();
    int n2=nums2.size();
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
        {
            int v=nums1[i]+nums2[j];
            val_pair t(v,nums1[i],nums2[j]);
            pq.push(t);
        }
    }
    vector<vector<int>> res;
    for(int i=0;i<k;i++)
    {
        val_pair t=pq.top();
        vector<int> tt;
        tt.push_back(t.p.first);
        tt.push_back(t.p.second);
        pq.pop();
        res.push_back(tt);
    }
    return res;
}

int main()
{
    int arr[6] = {1,7,11, 5, 6, 4};
    int brr[6] = {2,4,6, 5, 6, 4};

    vector<int> n1;
    vector<int> n2;

    for (int i = 0; i < 3; i++)
    {
        n1.push_back(arr[i]);
        n2.push_back(brr[i]);
    }
    vector<vector<int>> res = kSmallestPairs(n1, n2,3);
    // cout << 1;
    return 0;
}
