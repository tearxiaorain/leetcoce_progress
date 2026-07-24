#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

bool wordPattern(string pattern, string s) {
    map<char, string> ptos;
    map<string, char> stop;

    vector<string> words(0);
    string word = "";
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==' ')
        {
            words.push_back(word);
            word="";
        }
        else
        {
            word+=s[i];
        }
    }
    words.push_back(word);
    int np=pattern.length();
    if(np!=words.size())
        return false;

    int flag=0;
    for(int i=0;i<np;i++)
    {
        auto itp = ptos.find(pattern[i]);
        auto its = stop.find(words[i]);
        if(itp==ptos.end()&&its==stop.end())
        {
            ptos[pattern[i]]=words[i];
            stop[words[i]]=pattern[i];
        }
        else if(itp==ptos.end()||its==stop.end())
        {
            flag++;
            return false;
        }
        else
        {
            if(itp->second!=its->first||its->second!=itp->first)
            {
                flag++;
                return false;
            }
        }
    }
    if(!flag)
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
    cout << wordPattern("egg", "add") << endl;
    return 0;
}
