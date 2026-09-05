#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
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
    void add(int x)
    {
        myListNode *t=this;
        while(t->next!=nullptr)
        t=t->next;
        t->next=new myListNode(x,nullptr);
    }
};

myListNode *addTwoNumbers(myListNode *l1, myListNode *l2)
{
    int c = 0;
    myListNode *h1 = l1;
    myListNode *h2 = l2;
    while (h1 && h2)
    {
        h1 = h1->next;
        h2 = h2->next;
    }
    if (h1)
        ;
    else if (h2)
    {
        swap(l1, l2);
    }

    h1 = l1;
    while (l1 && l2)
    {
        l1->val += l2->val;
        if (l1->val >= 10)
        {
            if (l1->next == nullptr)
            {
                l1->next = new myListNode();
            }
            l1->next->val += l1->val / 10;
            l1->val %= 10;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1)
    {
        if (l1->val >= 10)
        {
            if (l1->next == nullptr)
            {
                l1->next = new myListNode();
            }
            l1->next->val += l1->val / 10;
            l1->val %= 10;
        }
        l1 = l1->next;
    }
    return h1;
}

int main()
{
    myListNode *l1 = new myListNode(0);
    myListNode *l2 = new myListNode(0);
    int arr[10]={9,9,9,9,9,9,9};
    int brr[10]={9,9,9,9};
    for(int i=0;i<7;i++)
    {
        l1->add(arr[i]);
        //l2->add(brr[i]);
    }
    for(int i=0;i<4;i++)
    {
        //l1->add(arr[i]);
        l2->add(brr[i]);
    }
    myListNode *l3;
    l3 = addTwoNumbers(l1, l2);
    cout << l3->val;
    return 0;
}
