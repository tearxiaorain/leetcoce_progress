#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int evalRPN(vector<string> &tokens)
{
    stack<int> s;
    int n = tokens.size();
    for (int i = 0; i < n; i++)
    {
        if (tokens[i] == "+")
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(b + a);
        }
        else if (tokens[i] == "-")
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(b - a);
        }
        else if (tokens[i] == "*")
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(b * a);
        }
        else if (tokens[i] == "/")
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(b / a);
        }
        else
        {
            s.push(stoi(tokens[i]));
        }
    }
    return s.top();
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
    cout << evalRPN(t);
    return 0;
}
