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

myListNode *sortList(myListNode *head)
{
    if (!head)
        return head;
    if (head->next == nullptr)
        return head;
    if (head->next->next == nullptr)
    {
        myListNode *h = new myListNode(head->val);
        myListNode *hh = new myListNode(head->next->val);
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

    myListNode *l = head;
    myListNode *r = head;
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
    myListNode *ll = sortList(l);
    myListNode *rr = sortList(r);

    myListNode *h;
    l=ll;
    r=rr;
    if (l->val > r->val)
    {
        h = new myListNode(r->val);
        r = r->next;
    }
    else
    {
        h = new myListNode(l->val);
        l = l->next;
    }
    myListNode *res = h;
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
    myListNode *h=new myListNode(arr[0]);
    myListNode *hh = h;

    for (int i = 1; i < 5; i++)
    {
        //a.push_back(arr[i]);
        hh->next = new myListNode(arr[i]);
        hh=hh->next;
    }
    myListNode *r = sortList(h);
    cout << 1;
    return 0;
}
