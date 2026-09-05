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

myListNode* reverseBetween1(myListNode* head, int left, int right) {
    stack<int> st;
    myListNode* l=head;
    int count=1;
    while(count<left)
    {
        l=l->next;
        count++;
    }
    myListNode* t=l;
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

myListNode* reverseBetween(myListNode* head, int left, int right) {
    // 使用 dummy 节点统一处理 left==1 的情况
    myListNode* dummy = new myListNode(0, head);
    myListNode* pre = dummy;

    // pre 走到 left 的前一个节点
    for (int i = 1; i < left; i++) {
        pre = pre->next;
    }

    // current 指向 left 节点
    myListNode* current = pre->next;
    myListNode* h = current;          // h 记录反转后的尾节点（原 left 节点）
    myListNode* prev = nullptr;

    // 反转 left 到 right 的节点（共 right-left+1 个）
    for (int i = left; i <= right; i++) {
        myListNode* next_t = current->next;
        current->next = prev;
        prev = current;
        current = next_t;
    }

    // 连接：pre 接反转后的头(prev)，反转后的尾(h)接剩余部分(current)
    pre->next = prev;
    h->next = current;

    myListNode* newHead = dummy->next;
    delete dummy;
    return newHead;
}

int main()
{
    myListNode *l1 = new myListNode(5);
    myListNode *l2 = new myListNode(0);
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
    myListNode *l3;
    l3 = reverseBetween(l1, 1,2);
    cout << l3->val;
    return 0;
}
