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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode * n1=head;
        if(n1==nullptr)
            return false;
        ListNode * n2=head->next;
        if(n2==nullptr)
            return false;
        while(n1!=nullptr&&n2!=nullptr)
        {
            n1=n1->next;
            n2=n2->next;
            if(n2==nullptr)
                return false;
            n2=n2->next;
            if(n2==nullptr)
                return false;
            if(n1==n2)
                return true;
        }
        return false;
    }
};

int main()
{
    vector<string> t;
    string s[13] = {"10", "6", "9", "3", "+",
                    "-11", "*", "/", "*", "17",
                    "+", "5", "+"};
    for (int i = 0; i < 13; i++)
    {
        t.push_back(s[i]);
    }
    cout << calculate("-2+ 1");
    return 0;
}
