#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <math.h>

using namespace std;

void fun(vector<vector<double>> g, vector<vector<int>> g_flag,vector<int> &flag, int a,int b,double &r,bool &f)
{
    if(g_flag[a][b])
    {
        f=true;
        r*=g[a][b];
        return;
    }
    int n=g.size();
    for(int i=0;i<n;i++)
    {
        if(g_flag[a][i])
        {
            if(!flag[i])
            {
                flag[i]=1;
                r*=g[a][i];
                fun(g,g_flag,flag,i,b,r,f);
                if(f)
                    return;
                r/=g[a][i];
                flag[i]=0;
            }
        }
    }
    return;
}

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    vector<double> res;
    
    unordered_map<string,int> um;
    int cnt=0;
    for(int i=0;i<values.size();i++)
    {
        auto it1=um.find(equations[i][0]);
        auto it2=um.find(equations[i][1]);
        if(it1==um.end())
        {
            um[equations[i][0]]=cnt;
            cnt++;
        }
        if(it2==um.end())
        {
            um[equations[i][1]]=cnt;
            cnt++;
        }
    }
    vector<vector<double>> g;
    vector<vector<int>> g_flag;

    for(int i=0;i<cnt;i++)
    {
        vector<double> t(cnt,0);
        vector<int> tt(cnt,0);
        g.push_back(t);
        g_flag.push_back(tt);
    }

    for(int i=0;i<values.size();i++)
    {
        auto it1=um.find(equations[i][0]);
        auto it2=um.find(equations[i][1]);
        g[it1->second][it2->second]=values[i];
        g[it2->second][it1->second]=1.0/values[i];
        g_flag[it1->second][it2->second]=g_flag[it2->second][it1->second]=1;
    }

    for(int i=0;i<queries.size();i++)
    {
        auto it1=um.find(queries[i][0]);
        auto it2=um.find(queries[i][1]);
        if(it1==um.end())
        {
            res.push_back(-1.0);
            continue;
        }
        if(it2==um.end())
        {
            res.push_back(-1.0);
            continue;
        }
        vector<int> flag(cnt,0);
        flag[it1->second]=1;
        double r=1;
        bool f = false;
        fun(g,g_flag,flag,it1->second,it2->second,r,f);
        if(f)
            res.push_back(r);
        else
            res.push_back(-1.0);
    }
    return res;
}

int main()
{
    vector<vector<string>> equations; vector<double> values; vector<vector<string>> queries;
    string srr[2][2]={"a","b","b","c"};
    double drr[2]={2,3};
    string srr1[4][2]={"a","c","b","a","a","e","a","a"};

    for(int i=0;i<2;i++)
    {
        vector<string> t;
        vector<double> tt;
        t.push_back(srr[i][0]);
        t.push_back(srr[i][1]);
        values.push_back(drr[i]);
        equations.push_back(t);
    }
    for(int i=0;i<4;i++)
    {
        vector<string> t;
        t.push_back(srr1[i][0]);
        t.push_back(srr1[i][1]);
        queries.push_back(t);
    }

    vector<double> res = calcEquation(equations,values,queries);
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    cout << endl << 1;
    return 0;
}