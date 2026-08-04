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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    void add(int x)
    {
        ListNode *t = this;
        while (t->next != nullptr)
            t = t->next;
        t->next = new ListNode(x, nullptr);
    }
};

ListNode* reverseBetween(ListNode* head, int left, int right) {
    stack<int> st;
    ListNode* l=head;
    int count=1;
    while(count<left)
    {
        l=l->next;
        count++;
    }
    ListNode* t=l;
    for(int i=left;i<=right;i++)
    {
        st.push(t->val);
        t=t->next;
    }
    for(int i=left;i<=right;i++)
    {
        l->val=st.top();
        st.pop();
        l=l->next;
    }
    return head;
}

int main()
{
    ListNode *l1 = new ListNode(5);
    ListNode *l2 = new ListNode(0);
    int arr[10] = {1,2,3,4,5, 9, 9};
    int brr[10] = {1,3,4, 9};
    for (int i = 1; i < 2; i++)
    {
        l1->add(arr[i]);
        //l2->add(brr[i]);
    }
    // for (int i = 0; i < 4; i++)
    // {
    //     // l1->add(arr[i]);
    //     l2->add(brr[i]);
    // }
    ListNode *l3;
    l3 = reverseBetween(l1, 1,2);
    cout << l3->val;
    return 0;
}
