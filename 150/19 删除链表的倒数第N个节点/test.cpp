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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    int cnt = -1;
    unordered_map<int, ListNode *> m;
    ListNode *res = new ListNode(0);
    res->next = head;
    ListNode *h = res;
    while (h)
    {
        cnt++;
        m[cnt] = h;
        h = h->next;
    }
    int k = cnt - n;
    auto it = m.find(k);
    it->second->next = it->second->next->next;
    return res->next;
}

int main()
{
    // cout << 1;
    return 0;
}
