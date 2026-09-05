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
        myListNode *t = this;
        while (t->next != nullptr)
            t = t->next;
        t->next = new myListNode(x, nullptr);
    }
};

myListNode *mergeTwoLists(myListNode *list1, myListNode *list2)
{
    myListNode *l = new myListNode();
    myListNode *r = l;
    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            l->next = new myListNode(list1->val, nullptr);
            list1 = list1->next;
        }
        else
        {
            l->next = new myListNode(list2->val, nullptr);
            list2 = list2->next;
        }
        l = l->next;
    }
    if (list1)
        l->next = list1;
    else
        l->next = list2;
    return r->next;
}

int main()
{
    myListNode *l1 = new myListNode(0);
    myListNode *l2 = new myListNode(0);
    int arr[10] = {1,2,4, 9, 9, 9, 9};
    int brr[10] = {1,3,4, 9};
    for (int i = 0; i < 3; i++)
    {
        l1->add(arr[i]);
        l2->add(brr[i]);
    }
    // for (int i = 0; i < 4; i++)
    // {
    //     // l1->add(arr[i]);
    //     l2->add(brr[i]);
    // }
    myListNode *l3;
    l3 = mergeTwoLists(l1, l2);
    cout << l3->val;
    return 0;
}
