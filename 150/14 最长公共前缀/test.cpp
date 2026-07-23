#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    int n = strs.size();
    string s = "";
    int lenmin = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (strs[i].length() < lenmin)
        {
            lenmin = strs[i].length();
        }
    }
    for (int i = 0; i < lenmin; i++)
    {
        char c = strs[0][i];
        for (int j = 1; j < n; j++)
        {
            if (strs[j][i] != c)
            {
                return s;
            }
        }
        s += c;
    }
    return s;
}

int main()
{
    vector<string> strs;
    string arr[7] = {"apple", "application", "apply", "approach", "april", "apricot", "apology"};
    for (int i = 0; i < 7; i++)
    {
        strs.push_back(arr[i]);
    }
    cout << longestCommonPrefix(strs) << endl;
    return 0;
}
