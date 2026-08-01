#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

string simplifyPath(string path)
{
    stack<string> st;
    string word = "";
    for (int i = 0; i < path.length(); i++)
    {
        if (path[i] == '/')
        {
            if (word == "." || word == "")
                ;
            else if (word == "..")
            {
                if (!st.empty())
                    st.pop();
            }
            else
                st.push(word);
            word = "";
        }
        else
        {
            word += path[i];
        }
    }
    if (word == "." || word == "")
        ;
    else if (word == "..")
    {
        if (!st.empty())
            st.pop();
    }
    else
        st.push(word);
    string p = "";
    while (!st.empty())
    {
        string w = st.top();
        st.pop();
        p = w + p;
        p = "/" + p;
    }
    if (p == "")
        p = "/" + p;
    return p;
}

int main()
{
    vector<string> s = {"/home/", "/home//foo/",
                        "/home/user/Documents/../Pictures",
                        "/../", "/.../a/../b/c/../d/./"};
    for (int i = 0; i < s.size(); i++)
    {
        cout << simplifyPath(s[i]) << endl;
    }

    return 0;
}
