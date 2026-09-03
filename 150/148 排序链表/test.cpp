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

ListNode *sortList(ListNode *head)
{
    if (!head)
        return head;
    if (head->next == nullptr)
        return head;
    if (head->next->next == nullptr)
    {
        ListNode *h = new ListNode(head->val);
        ListNode *hh = new ListNode(head->next->val);
        if (h->val > hh->val)
        {
            hh->next = h;
            return hh;
        }
        else
        {
            h->next = hh;
            return h;
        }
    }

    ListNode *l = head;
    ListNode *r = head;
    while (r->next)
    {
        l = l->next;
        r = r->next;
        if (r->next)
            r = r->next;
    }
    r = l->next;
    l->next=nullptr;
    l = head;
    ListNode *ll = sortList(l);
    ListNode *rr = sortList(r);

    ListNode *h;
    l=ll;
    r=rr;
    if (l->val > r->val)
    {
        h = new ListNode(r->val);
        r = r->next;
    }
    else
    {
        h = new ListNode(l->val);
        l = l->next;
    }
    ListNode *res = h;
    while (l && r)
    {
        if (l->val < r->val)
        {
            h->next = l;
            l = l->next;
            h=h->next;
        }
        else
        {
            h->next = r;
            r = r->next;
            h=h->next;
        }
    }
    if(l)
        h->next=l;
    else
        h->next=r;
    return res;
}

int main()
{
    int arr[5] = {-1,5,3,4,0};
    //vector<int> a;
    ListNode *h=new ListNode(arr[0]);
    ListNode *hh = h;

    for (int i = 1; i < 5; i++)
    {
        //a.push_back(arr[i]);
        hh->next = new ListNode(arr[i]);
        hh=hh->next;
    }
    ListNode *r = sortList(h);
    cout << 1;
    return 0;
}
