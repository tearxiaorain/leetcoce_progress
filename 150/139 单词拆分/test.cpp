#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    vector<string> srr;
    int n=s.length();
    string t="";
    srr.push_back(t);
    for(int i=0;i<n;i++)
    {
        t+=s[i];
        srr.push_back(t);
    }
    vector<string> str;
    str.push_back("");
    int nw=wordDict.size();
    for(int i=1;i<=n;i++)
    {
        int flag=0;
        for(int j=0;j<nw;j++)
        {
            int len=wordDict[j].length();
            if(i-len>=0)
            {
                if(str[i-len]+wordDict[j]==srr[i])
                {
                    flag++;
                    break;
                }
            }
        }
        if(flag)
            str.push_back(srr[i]);
        else
            str.push_back("");
    }
    if(str[n]==s)
        return true;
    return false;
}

int main()
{   
    vector<string> wordDict;
    string s[10]={"leet", "code"};
    for(int i=0;i<2;i++)
    {
        wordDict.push_back(s[i]);
    }
    cout << wordBreak("leetcode",wordDict);
    return 0;
}
