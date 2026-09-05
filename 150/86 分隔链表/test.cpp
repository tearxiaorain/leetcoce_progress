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

myListNode *partition(myListNode *head, int x)
{
    myListNode *l1 = new myListNode(0);
    l1->next = head;
    myListNode *l2;
    l2 = l1;
    myListNode *res = l1;
    if (!head)
        return nullptr;
    if (!head->next)
        return head;

    while (l1->next)
    {
        if (l1->next->val < x)
            l1 = l1->next;
        else
            break;
    }
    l2 = l1;

    while (l2->next)
    {
        if (l2->next->val >= x)
        {
            l2 = l2->next;
        }
        else
        {
            myListNode *t = l2->next->next;
            l2->next->next = l1->next;
            l1->next = l2->next;
            l1 = l1->next;
            l2->next = t;
        }
    }

    return res->next;
}

int main()
{

    // cout << 1;
    return 0;
}
