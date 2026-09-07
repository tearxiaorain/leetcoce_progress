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
    vector<int> flag;
    vector<TrieTreeNode *> next;
    bool isWord;
    TrieTreeNode() : flag(26, 0), next(26, nullptr), isWord(false) {}
};

class Trie
{
public:
    TrieTreeNode *root;
    Trie()
    {
        root = new TrieTreeNode();
    }

    void insert(string word)
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

    bool search(string word)
    {
        int l = word.length();
        TrieTreeNode *r = root;
        for (int i = 0; i < l; i++)
        {
            int k = word[i] - 'a';
            if (!r->next[k])
            {
                return false;
            }
            r = r->next[k];
        }
        if (r->isWord)
            return true;
        return false;
    }

    bool startsWith(string prefix)
    {
        int l = prefix.length();
        TrieTreeNode *r = root;
        for (int i = 0; i < l; i++)
        {
            int k = prefix[i] - 'a';
            if (!r->next[k])
            {
                return false;
            }
            r = r->next[k];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main()
{
    // cout << 1;
    return 0;
}
