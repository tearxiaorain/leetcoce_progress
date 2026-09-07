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

ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *res = new ListNode(0);
    res->next = head;
    ListNode *l1 = res;
    ListNode *l2 = res;
    ListNode *r = res;
    int flag = 0;

    while (r->next)
    {
        l1 = r->next;
        if (!l1)
            break;
        if (l1->next)
        {
            // l1在重复区间第一个
            if (l1->val == l1->next->val)
            {
                l2 = l1;
                while (l2->next)
                {
                    if (l2->next)
                    {
                        // l2在重复区间最后一个
                        if (l2->val != l2->next->val)
                            break;
                        l2 = l2->next;
                    }
                }
                r->next = l2->next;
                flag = 1;
            }
        }
        if (!r->next)
            break;
        if (!flag)
            r = r->next;
        flag = 0;
    }
    return res->next;
}

int main()
{
    // [1,2,3,3,4,4,5]
    int arr[7] = {1, 2, 3, 3, 4, 4, 5};
    ListNode *head = new ListNode(1);
    ListNode *h = head;
    for (int i = 1; i < 7; i++)
    {
        h->next = new ListNode(arr[i]);
        h = h->next;
    }
    h = deleteDuplicates(head);
    // cout << 1;
    return 0;
}
