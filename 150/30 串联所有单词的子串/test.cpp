#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> findSubstring(string s, vector<string> &words)
{
    vector<int> res;
    int n = words.size();
    int l = words[0].length();
    int len = s.length();
    unordered_map<string, int> m_word;
    unordered_map<string, int> m_use;

    for (int i = 0; i < n; i++)
    {
        auto itw = m_word.find(words[i]);
        if (itw == m_word.end())
            m_word[words[i]] = 1;
        else
            itw->second++;
    }

    int r1, r2;
    r1 = r2 = 0;
    int cnt = 0;
    for (int i = 0; i < l; i++)
    {
        r1 = i;
        r2 = i;
        cnt = 0;
        for (auto iti : m_use)
        {
            m_use[iti.first] = 0;
        }
        while (r1 + l <= len)
        {
            string sr1 = s.substr(r1, l);
            // 找到第一个字典中的词
            while (r1 == r2 && r1 + l <= len)
            {
                sr1 = s.substr(r1, l);
                auto it0 = m_word.find(sr1);
                if (it0 == m_word.end())
                {
                    r1 += l;
                    r2 += l;
                }
                else
                {
                    auto it00 = m_use.find(sr1);
                    if (it00 == m_use.end())
                        m_use[sr1] = 1;
                    else
                        m_use[sr1]++;
                    cnt++;
                    if (cnt == n)
                    {
                        res.push_back(r1);
                        m_use[sr1]--;
                        cnt--;
                        r1 += l;
                        r2 += l;
                        continue;
                    }
                    r2 += l;
                }
            }

            while (r2 + l <= len)
            {
                string sr2 = s.substr(r2, l);
                auto it = m_word.find(sr2);
                if (it == m_word.end())
                    break;
                else
                {
                    auto itt = m_use.find(sr2);
                    if (itt == m_use.end())
                    {
                        m_use[sr2] = 1;
                        cnt++;
                        r2 += l;
                        if (cnt == n)
                        {
                            res.push_back(r1);
                            break;
                        }
                    }
                    else
                    {
                        if (itt->second < it->second)
                        {
                            m_use[sr2]++;
                            cnt++;
                            r2 += l;
                            if (cnt == n)
                            {
                                res.push_back(r1);
                                break;
                            }
                        }
                        else
                            break;
                    }
                }
            }
            // m_use.erase(sr1);
            m_use[sr1]--;
            cnt--;
            r1 += l;
        }
    }

    return res;
}

int main()
{
    int nrr[15] = {4, 4, 1000, 1, 1, 1, 5}; // 1008 , 3
    string s = "aaa";
    // lingmindraboo fooo wing ding barr wing monkeypoundcake
    string srr[5] = {"a", "barr", "wing", "ding", "wing"};
    vector<string> strs;
    for (int i = 0; i < 1; i++)
    {
        strs.push_back(srr[i]);
    }
    vector<int> r = findSubstring(s, strs);
    for (int i = 0; i < r.size(); i++)
    {
        cout << r[i] << endl;
    }
    // cout << 1;
    return 0;
}
