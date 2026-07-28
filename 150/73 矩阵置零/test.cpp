#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    map<int,int> mn;
    map<int,int> mm;
    int n=matrix.size();
    int m=matrix[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!matrix[i][j])
            {
                auto it=mn.find(i);
                if(it==mn.end())
                {
                    mn[i]=i;
                }
                it=mm.find(j);
                if(it==mm.end())
                {
                    mm[j]=j;
                }
            }   
        }
    }
    for(auto it=mn.begin();it!=mn.end();it++)
    {
        for(int i=0;i<m;i++)
        {
            matrix[it->first][i]=0;
        }
    }
    for(auto it=mm.begin();it!=mm.end();it++)
    {
        for(int i=0;i<n;i++)
        {
            matrix[i][it->first]=0;
        }
    }
}

int main()
{
    vector<vector<int>> m;
    int arr[5][5] = {1,2,3,4,5,
                    6,7,8,9,10,
                    11,12,13,14,15,
                    16,17,18,19,20,
                    21,22,23,24,25};
    for(int i=0;i<5;i++)
    {
        vector<int> t(0);
        for(int j=0;j<5;j++)
        {
            t.push_back(arr[i][j]);
        }
        m.push_back(t);
    }

    setZeroes(m);
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
