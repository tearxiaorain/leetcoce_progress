#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

bool isSubsequence(string s, string t) {
    int i,j;
    i=j=0;
    int ns=s.length();
    int nt=t.length();
    int count=0;
    for(;i<nt;i++)
    {
        if(s[j]==t[i])
        {
            count++;
            j++;
        }
    }
    if(count==ns)
        return true;
    return false;
}

int main()
{
    vector<string> strs;
    vector<int> nums;
    string arr[6] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    for (int i = 0; i < 6; i++)
    {
        strs.push_back(arr[i]);
    }
    int nrr[6] = {100,4,200,1,3,2};
    for (int i = 0; i < 6; i++)
    {
        nums.push_back(nrr[i]);
    }
    cout << isSubsequence("abc","ahbgdc");
    return 0;
}
