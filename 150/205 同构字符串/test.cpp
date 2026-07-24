#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

bool isIsomorphic(string s, string t)
{
    vector<char> srr(0);
    vector<char> trr(0);
    vector<int> sss(0);
    vector<int> ttt(0);

    int ns = s.length();
    int nt = t.length();
    if (ns != nt)
        return false;

    for (int i = 0; i < ns; i++)
    {
        int flags = 0;
        for (int j = 0; j < srr.size(); j++)
        {
            if (s[i] == srr[j])
            {
                sss.push_back(j);
                flags++;
                break;
            }
        }
        if (!flags)
        {
            sss.push_back(srr.size());
            srr.push_back(s[i]);
        }
    }
    for (int i = 0; i < nt; i++)
    {
        int flagt = 0;
        for (int j = 0; j < trr.size(); j++)
        {
            if (t[i] == trr[j])
            {
                ttt.push_back(j);
                flagt++;
                break;
            }
        }
        if (!flagt)
        {
            ttt.push_back(trr.size());
            trr.push_back(t[i]);
        }
    }

    int flag = 0;
    for (int i = 0; i < ns; i++)
    {
        if (sss[i] != ttt[i])
        {
            flag++;
            break;
        }
    }
    if (!flag)
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
    cout << isIsomorphic("egg", "add") << endl;
    return 0;
}
