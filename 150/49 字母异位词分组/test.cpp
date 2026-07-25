#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    int num = strs.size();
    vector<int> a(num,0);
    vector<vector<int>> arr(0);
    for(int i=0;i<num;i++)
    {
        vector<int> temp(26,0);
        for(int j=0;j<strs[i].size();j++)
        {
            int ind = strs[i][j]-'a';
            temp[ind]++;
        }
        arr.push_back(temp);
    }
    map<vector<int>,int> m;
    int count=0;
    for(int i=0;i<num;i++)
    {
        auto it =m.find(arr[i]);
        if(it==m.end())
        {
            m[arr[i]]=count;
            a[i]=count;
            count++;
        }
        else
        {
            a[i]=it->second;
        }
    }
    vector<vector<string>> res(count);
    for(int i = 0;i<num;i++)
    {
        res[a[i]].push_back(strs[i]);
    }
    return res;
}


int main()
{
    vector<string> strs;
    string arr[6] = {"eat","tea","tan","ate","nat","bat"};
    for (int i = 0; i < 6; i++)
    {
        strs.push_back(arr[i]);
    }
    vector<vector<string>> res = groupAnagrams(strs);
    return 0;
}
