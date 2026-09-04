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

int lengthOfLongestSubstring1(string s) {
    int len=s.length();
    int max=0;
    for(int i=0;i<len;i++)
    {
        unordered_map <char,int> m;
        int l=0;
        for(int j=i;j<len;j++)
        {
            auto it=m.find(s[j]);
            if(it==m.end())
            {
                m[s[j]]=j;
                l++;
            }
            else break;
        }
        if(max<l)
            max=l;
    }
    return max;
}

int lengthOfLongestSubstring(string s) {
    int len=s.length();
    int max=0;
    unordered_map <char,int> m;
    int l,r;
    l=r=0;
    int cnt=0;
    while(l<len)
    {
        // 找到以l开头的最长不重复子串
        while(r<len)
        {
            auto it=m.find(s[r]);
            if(it==m.end())
            {
                m[s[r]]=r;
                cnt++;
            }
            else break;
            r++;
        }
        if(max<cnt)
            max=cnt;
        // 下一轮从l+1开始  且此时从l到r-1都是无重复的  下次继续从r开始判断
        m.erase(s[l]);
        cnt--;
        l++;
    }
    return max;
}

int main()
{
    int nrr[15] = {4,4,1000,1,1,1,5};  // 1008 , 3
    string s="abcabcbb";
    vector<int> nums;
    for (int i = 0; i < 7; i++)
    {
        nums.push_back(nrr[i]);
    }
    cout<< lengthOfLongestSubstring(s);
    //cout << 1;
    return 0;
}
