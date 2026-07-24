#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

bool isAnagram(string s, string t) {
    int ns = s.length();
    int nt = t.length();
    if(ns!=nt)
        return false;

    sort(s.begin(),s.end());
    sort(t.begin(),t.end());

    int flag=0;
    for(int i=0;i<ns;i++)
    {
        if(s[i]!=t[i])
        {
            flag++;
            break;
        }
    }
    if(!flag)
        return true;
    return false;
}

int main()
{
    vector<string> strs;
    string arr[7] = {"apple", "application", "apply", "approach", "april", "apricot", "apology"};
    for (int i = 0; i < 7; i++)
    {
        strs.push_back(arr[i]);
    }
    cout << wordPattern("egg", "add") << endl;
    return 0;
}
