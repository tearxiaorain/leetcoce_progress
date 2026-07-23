#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

string reverseWords(string s)
{
    stack<string> words;
    int n = s.length();
    string word = "";
    for (int i = 0; i < n; i++)
    {
        if (s[i] != ' ')
        {
            word += s[i];
        }
        else
        {
           if(word != "")
            {
                words.push(word);
            }
            word = "";
        }
    }
    if(word != "")
    {
        words.push(word);
    }
    string str = "";
    n = words.size();
    if (n)
    {
        str += words.top();
        words.pop();
        for (int i = 1; i < n; i++)
        {
            str+= " ";
            str += words.top();
            words.pop();
        }
    }
    return str;
}

int main()
{
    vector<string> strs;
    string arr[7] = {"apple", "application", "apply", "approach", "april", "apricot", "apology"};
    for (int i = 0; i < 7; i++)
    {
        strs.push_back(arr[i]);
    }
    cout << reverseWords("  hello world  ") << endl;
    return 0;
}
