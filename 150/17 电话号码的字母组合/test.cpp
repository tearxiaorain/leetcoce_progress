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

void fun(string digits,vector<vector<char>> d_s,vector<string> &res,vector<char> &path,int n,int k)
{
    if(k<n)
    {
        int c=digits[k]-'0';
        for(int j=0;j<d_s[c-1].size();j++)
        {
            path.push_back(d_s[c-1][j]);
            fun(digits,d_s,res,path,n,k+1);
            path.pop_back();
        }
    }
    else
    {
        string s="";
        for(int i=0;i<n;i++)
        {
            s+=path[i];
        }
        res.push_back(s);
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> res;
    vector<vector<char>> d_s;
    vector<char> t;
    d_s.push_back(t);
    t.push_back('a');   t.push_back('b');   t.push_back('c');   d_s.push_back(t);
    t[0]='d';   t[1]='e';   t[2]='f';       d_s.push_back(t);
    t[0]='g';   t[1]='h';   t[2]='i';       d_s.push_back(t);
    t[0]='j';   t[1]='k';   t[2]='l';       d_s.push_back(t);
    t[0]='m';   t[1]='n';   t[2]='o';       d_s.push_back(t);
    t[0]='p';   t[1]='q';   t[2]='r';       t.push_back('s');   d_s.push_back(t);
    t.pop_back();t[0]='t';  t[1]='u';       t[2]='v';           d_s.push_back(t);
    t[0]='w';   t[1]='x';   t[2]='y';       t.push_back('z');   d_s.push_back(t);

    int n=digits.length();
    vector<int> flag(n,0);
    vector<char> path;
    fun(digits,d_s,res,path,n,0);
    return res;
}

int main()
{
    vector<string> r = letterCombinations("6");
    for(int i=0;i<r.size();i++)
    {
        cout<<r[i]<<endl;
    }
    return 0;
}
