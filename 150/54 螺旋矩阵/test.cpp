#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res(0);
    int factor=0;
    vector<vector<int>> flag;
    int n=matrix.size();
    int m=matrix[0].size();
    for(int i=0;i<n;i++)
    {
        vector<int> temp(m,0);
        flag.push_back(temp);
    }
    int k1=0;
    int k2=0;
    for(int i=0;i<n*m;i++)
    {
        res.push_back(matrix[k1][k2]);
        flag[k1][k2]++;
        if(factor%4==0)  // right
        {
            int flag0=0;
            if(k2+1<m)
            {
                if(!flag[k1][k2+1])
                {
                    flag0++;
                    k2++;
                }
            }
            if(!flag0)
            {
                factor++;
                k1++;
            }
        }
        else if(factor%4==1) // down
        {
            int flag0=0;
            if(k1+1<n)
            {
                if(!flag[k1+1][k2])
                {
                    flag0++;
                    k1++;
                }
            }
            if(!flag0)
            {
                factor++;
                k2--;
            }
        }
        else if(factor%4==2) // left
        {
            int flag0=0;
            if(k2-1>=0)
            {
                if(!flag[k1][k2-1])
                {
                    flag0++;
                    k2--;
                }
            }
            if(!flag0)
            {
                factor++;
                k1--;
            }
        }
        else if(factor%4==3) // up
        {
            int flag0=0;
            if(k1-1>=0)
            {
                if(!flag[k1-1][k2])
                {
                    flag0++;
                    k1--;
                }
            }
            if(!flag0)
            {
                factor++;
                k2++;
            }
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> m;
    int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    for(int i=0;i<3;i++)
    {
        vector<int> t(0);
        for(int j=0;j<4;j++)
        {
            t.push_back(arr[i][j]);
        }
        m.push_back(t);
    }

    vector<int> res = spiralOrder(m);
    return 0;
}
