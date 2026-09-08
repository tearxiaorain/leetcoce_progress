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

struct TrieTreeNode
{
    vector<TrieTreeNode *> next;
    bool isWord;
    TrieTreeNode() : next(26, nullptr), isWord(false) {}
};

class WordDictionary
{
public:
    TrieTreeNode *root;
    WordDictionary()
    {
        root = new TrieTreeNode();
    }

    void addWord(string word)
    {
        int l = word.length();
        TrieTreeNode *r = root;
        for (int i = 0; i < l; i++)
        {
            int k = word[i] - 'a';
            if (!r->next[k])
            {
                r->next[k] = new TrieTreeNode();
            }
            r = r->next[k];
        }
        r->isWord = true;
    }

    bool searchFrom(string word, TrieTreeNode *t)
    {
        int l = word.length();
        TrieTreeNode *r = t;
        // 终止条件
        if (l == 1)
        {
            if (word[0] == '.')
            {
                for (int i = 0; i < 26; i++)
                {
                    if (t->next[i])
                    {
                        if (t->next[i]->isWord)
                            return true;
                    }
                }
                return false;
            }
            else
            {
                int k = word[0] - 'a';
                if (!t->next[k])
                    return false;
                if (t->next[k]->isWord)
                    return true;
                return false;
            }
        }

        if (word[0] == '.')
        {
            for (int j = 0; j < 26; j++)
            {
                if (!r->next[j])
                    continue;
                bool b = this->searchFrom(word.substr(1, l - 1), r->next[j]);
                if (b)
                    return b;
            }
            return false;
        }
        else
        {
            int k = word[0] - 'a';
            if (!t->next[k])
                return false;
            return this->searchFrom(word.substr(1, l - 1), r->next[k]);
        }

        return false;
    }

    bool search(string word)
    {
        return searchFrom(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main()
{
    // ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
    // [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
    WordDictionary *wd = new WordDictionary();
    string srr[7] = {"bad", "dad", "mad", "pad", "bad", ".ad", "b.."};
    wd->addWord(srr[0]);
    wd->addWord(srr[1]);
    wd->addWord(srr[2]);
    cout << wd->search(srr[3]);
    cout << wd->search(srr[4]);
    cout << wd->search(srr[5]);
    cout << wd->search(srr[6]);

    // cout << 1;
    return 0;
}
