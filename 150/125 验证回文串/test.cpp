#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

bool isPalindrome(string s) {
    string str="";
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='a'&&s[i]<='z')
        {
            str+=s[i];
        }
        else if(s[i]>='A'&&s[i]<='Z')
        {
            str+=(s[i]-'A'+'a');
        }
        else if(s[i]>='0'&&s[i]<='9')
        {
            str+=(s[i]);
        }
    }
    int n=str.length();
    int flag=0;
    int i=0;
    int j=n-1;
    while(i<j)
    {
        if(str[i]!=str[j])
        {
            flag++;
            return false;
        }
        i++;
        j--;
    }
    if(!flag)
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
    cout << isPalindrome("");
    return 0;
}
