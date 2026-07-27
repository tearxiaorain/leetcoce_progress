#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    //int n=intervals.size();
    vector<vector<int>> res = intervals;
    while(1)
    {
        int flag0=0;
        vector<vector<int>> r(0);
        r.push_back({res[0][0],res[0][1]});
        int count=1;
        int n=res.size();
        for(int i=1;i<n;i++)
        {
            int ind1=res[i][0];
            int ind2=res[i][1];
            int temp=0;
            for(int j=0;j<count;j++)
            {
                int flag=0;
                int ind3=r[j][0];
                int ind4=r[j][1];
                if(ind1>ind4||ind2<ind3)
                {}
                else 
                {
                    flag++;
                    if(ind1<ind3)
                        r[j][0]=ind1;
                    if(ind2>ind4)
                        r[j][1]=ind2;
                    flag0++;
                }
                if(!flag)
                {
                    temp++;
                }
            }
            if(temp==count)
            {
                vector<int> temp;
                temp.push_back(ind1);
                temp.push_back(ind2);
                r.push_back(temp);
                count++;
            }
        }
        res=r;
        if(!flag0)
        {
            break;
        }
    }

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
    int n[4] = {1,4,0,5};
    for(int i=0;i<4;i+=2)
    {
        intervals.push_back({n[i],n[i+1]});
    }

    vector<vector<int>> res = merge(intervals);
    return 0;
}
