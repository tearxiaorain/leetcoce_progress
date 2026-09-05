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

myListNode *rotateRight(myListNode *head, int k)
{
    if (k == 0)
        return head;
    myListNode *h = head;
    int n = 0;
    if (h)
        n = 1;
    else
        return nullptr;

    while (h->next)
    {
        n++;
        h = h->next;
    }
    // 成环
    h->next = head;

    int r = k % n;
    h = head;
    r = n - r - 1;
    while (r--)
    {
        h = h->next;
    }
    myListNode *res = h->next;
    h->next = nullptr;

    return res;
}

int main()
{

    // cout << 1;
    return 0;
}
