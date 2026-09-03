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

int snakesAndLadders(vector<vector<int>>& board) {
    int n=board.size();
    int factor=0;
    vector<int> b;
    unordered_map<int,vector<int>> m;
    for(int i=n-1;i>=0;i--)
    {
        factor=1-factor;
        if(factor)
        {
            for(int j=0;j<n;j++)
            {
                b.push_back(board[i][j]);
                if(board[i][j]!=-1)
                {
                    int c=b.size();
                    auto it=m.find(board[i][j]);
                    if(it==m.end())
                    {
                        vector<int> t;
                        t.push_back(c);
                        m[board[i][j]]=t;
                    }
                    else
                    {
                        it->second.push_back(c);
                    }
                }
            }
        }
        else
        {
            for(int j=n-1;j>=0;j--)
            {
                b.push_back(board[i][j]);
                if(board[i][j]!=-1)
                {
                    int c=b.size();
                    auto it=m.find(board[i][j]);
                    if(it==m.end())
                    {
                        vector<int> t;
                        t.push_back(c);
                        m[board[i][j]]=t;
                    }
                    else
                    {
                        it->second.push_back(c);
                    }
                }
            }
        }
    }
    vector<int> r(n*n+1,0);
    r[1] = 0;
    for(int i=2;i<=6&&i<=n*n;i++)
    {
        r[i]=1;
    }
    for(int i=7;i<=n*n;i++)
    {
        auto it = m.find(i);
        int min=INT_MAX;
        if(it==m.end())
        {
            for(int j=1;j<=6;j++)
            {
                if(r[i-j]<min)
                    min=r[i-j];
            }
            r[i]=min+1;
        }
        else
        {
            int npath=it->second.size();
            for(int j=1;j<=6;j++)
            {
                if(r[i-j]<min)
                    min=r[i-j];
            }
            for(int j=0;j<npath;j++)
            {
                for(int k=1;k<=6;k++)
                {
                    if(it->second[j]-k>0)
                    {
                        if(r[it->second[j]-k]<min)
                            min=r[i-j];
                    }
                }
            }
            r[i]=min+1;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<i*n+j<<": "<<r[i*n+j]<<"      ";
        }
        cout<<endl;
    }
    return r[n*n];
}

int main()
{
    vector<vector<int>> b;
    int arr[6][6] = {-1,-1,-1,-1,-1,-1,
                    -1,-1,-1,-1,-1,-1,
                    -1,-1,-1,-1,-1,-1,
                    -1,35,-1,-1,13,-1,
                    -1,-1,-1,-1,-1,-1,
                    -1,15,-1,-1,-1,-1};
    for (int i = 0; i < 6; i++)
    {
        vector<int> g;
        for (int j = 0; j < 6; j++)
        {
            g.push_back(arr[i][j]);
        }
        b.push_back(g);
    }
    cout << snakesAndLadders(b);

    return 0;
}
