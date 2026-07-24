#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    string s1 = ransomNote;
    string s2 = magazine;
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    int n1 = s1.length();
    int n2 = s2.length();
    int ind1,ind2,count;
    ind1=ind2=count=0;
    while(ind1<n1)
    {
        if(ind2>=n2)
            break;
        if(s1[ind1]==s2[ind2])
        {
            ind1++;
            ind2++;
            count++;
        }
        else
            ind2++;
    }
    if(count==n1)
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
    cout << canConstruct("a", "b") << endl;
    return 0;
}
