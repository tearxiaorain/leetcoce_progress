#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int strStr(string haystack, string needle) {
     int n1=haystack.length();
     int n2=needle.length();
     int flag=0;
     int k=-1;
     for(int i=0;i<n1-n2;i++)
     {
        if(haystack[i]==needle[0])
        {
            int flag0=0;
            for(int j=0;j<n2;j++)
            {
                if(haystack[i+j]!=needle[j])
                {
                    flag0=1;
                    break;
                }
            }
            if(!flag0)
            {
                flag=0;
                k=i;
                break;
            }
        }
     }
     return k;   
}

int main()
{
    vector<string> strs;
    string arr[7] = {"apple", "application", "apply", "approach", "april", "apricot", "apology"};
    for (int i = 0; i < 7; i++)
    {
        strs.push_back(arr[i]);
    }
    cout << strStr("A", "A") << endl;
    return 0;
}
