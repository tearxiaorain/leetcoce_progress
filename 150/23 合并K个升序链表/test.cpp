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

struct myListNode
{
    int val;
    myListNode *next;
    myListNode() : val(0), next(nullptr) {}
    myListNode(int x) : val(x), next(nullptr) {}
    myListNode(int x, myListNode *next) : val(x), next(next) {}
};

myListNode *merge(myListNode *&l1, myListNode *&l2)
{
    myListNode *res = new myListNode(0);
    myListNode *t = res;
    myListNode *l = l1;
    myListNode *r = l2;
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

myListNode *mergeKLists(vector<myListNode *> &lists)
{
    int n = lists.size();
    if (n == 0)
        return nullptr;
    if (n == 1)
        return lists[0];
    if (n == 2)
        return merge(lists[0], lists[1]);
    vector<myListNode *> m1;
    vector<myListNode *> m2;
    for (int i = 0; i < n / 2; i++)
    {
        m1.push_back(lists[i]);
        m2.push_back(lists[i + n / 2]);
    }
    if (n % 2)
        m1.push_back(lists[n - 1]);
    myListNode *r1 = mergeKLists(m1);
    myListNode *r2 = mergeKLists(m2);
    return merge(r1, r2);
}

int main()
{
    cout << 1;
    return 0;
}
