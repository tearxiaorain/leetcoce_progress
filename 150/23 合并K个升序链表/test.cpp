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

ListNode *merge(ListNode *&l1, ListNode *&l2)
{
    ListNode *res = new ListNode(0);
    ListNode *t = res;
    ListNode *l = l1;
    ListNode *r = l2;
    while (l && r)
    {
        if (l->val < r->val)
        {
            res->next = l;
            l = l->next;
        }
        else
        {
            res->next = r;
            r = r->next;
        }
        res = res->next;
    }
    if (l)
        res->next = l;
    else
        res->next = r;
    return t->next;
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    int n = lists.size();
    if (n == 0)
        return nullptr;
    if (n == 1)
        return lists[0];
    if (n == 2)
        return merge(lists[0], lists[1]);
    vector<ListNode *> m1;
    vector<ListNode *> m2;
    for (int i = 0; i < n / 2; i++)
    {
        m1.push_back(lists[i]);
        m2.push_back(lists[i + n / 2]);
    }
    if (n % 2)
        m1.push_back(lists[n - 1]);
    ListNode *r1 = mergeKLists(m1);
    ListNode *r2 = mergeKLists(m2);
    return merge(r1, r2);
}

int main()
{
    cout << 1;
    return 0;
}
