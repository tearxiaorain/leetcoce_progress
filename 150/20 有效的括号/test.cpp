#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==')')
        {
            if(st.empty())
                return false;
            if(st.top()=='(')
            {
                st.pop();
            }
            else return false;
        }
        else if(s[i]==']')
        {
            if(st.empty())
                return false;
            if(st.top()=='[')
            {
                st.pop();
            }
            else return false;
        }
        else if(s[i]=='}')
        {
            if(st.empty())
                return false;
            if(st.top()=='{')
            {
                st.pop();
            }
            else return false;
        }
        else
        {
            st.push(s[i]);
        }
    }
    if(st.empty())
        return true;
    return false;
}

int main()
{
    cout << isValid("()");
    return 0;
}
