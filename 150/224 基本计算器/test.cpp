#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int calculate(string s)
{
    stack<int> st;
    stack<char> op;
    // op.push('[');
    // s = s + ']';
    int n = s.length();
    string snum = "";
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            snum += s[i];
        }
        else
        {
            if (s[i] == ' ')
            {
                continue;
            }
            else if (snum != "")
            {
                st.push(stoi(snum));
                snum = "";
            }
            if (s[i] == ')')
            {
                if (snum != "")
                {
                    st.push(stoi(snum));
                    snum = "";
                }
                stack<int> tempst;
                stack<char> tempop;
                tempst.push(st.top());
                st.pop();
                while (op.top() != '(')
                {
                    tempst.push(st.top());
                    st.pop();
                    tempop.push(op.top());
                    op.pop();
                }
                op.pop();
                while (!tempop.empty())
                {
                    int a = tempst.top();
                    tempst.pop();
                    int b = tempst.top();
                    tempst.pop();
                    if (tempop.top() == '+')
                    {
                        tempst.push(a + b);
                    }
                    else if (tempop.top() == '-')
                    {
                        tempst.push(a - b);
                    }
                    tempop.pop();
                }
                st.push(tempst.top());
            }
            else
            {
                if (!op.empty())
                {
                    if (op.top() == '*')
                    {
                        int a = st.top();
                        st.pop();
                        st.push(a * stoi(snum));
                        op.pop();
                        op.push(s[i]);
                    }
                    else if (op.top() == '/')
                    {
                        int a = st.top();
                        st.pop();
                        st.push(a / stoi(snum));
                        op.pop();
                        op.push(s[i]);
                    }
                    else if (s[i] == '-' && op.top() == '(')
                    {
                        snum += s[i];
                    }
                    // else if (snum != "")
                    // {
                    //     st.push(stoi(snum));
                    //     snum = "";
                    // }
                    // if (op.top() != '(')
                    else
                        op.push(s[i]);
                }
                else
                {
                    if(st.empty()&&s[i]=='-')
                    {
                        snum+=s[i];
                    }
                    else
                        op.push(s[i]);
                }
            }
        }
    }
    if(snum!="")
        st.push(stoi(snum));

    stack<int> tempst;
    stack<char> tempop;
    tempst.push(st.top());
    st.pop();
    if(!op.empty())
    {
        while (op.top() != '(')
        {
            tempst.push(st.top());
            st.pop();
            tempop.push(op.top());
            op.pop();
            if(op.empty())
                break;
        }
        //op.pop();
    }
    
    while (!tempop.empty())
    {
        int a = tempst.top();
        tempst.pop();
        int b = tempst.top();
        tempst.pop();
        if (tempop.top() == '+')
        {
            tempst.push(a + b);
        }
        else if (tempop.top() == '-')
        {
            tempst.push(a - b);
        }
        tempop.pop();
    }
    st.push(tempst.top());

    return st.top();
}

int main()
{
    vector<string> t;
    string s[13] = {"10", "6", "9", "3", "+",
                    "-11", "*", "/", "*", "17",
                    "+", "5", "+"};
    for (int i = 0; i < 13; i++)
    {
        t.push_back(s[i]);
    }
    cout << calculate("-2+ 1");
    return 0;
}
