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

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    unordered_map<int, Node *> index_n;
    unordered_map<Node *, int> n_index;
    int n = 0;
    if (!head)
        return nullptr;
    Node *h = head;
    Node *res = new Node(head->val);
    Node *r = res;
    n_index[h] = n;
    index_n[n] = r;
    n_index[nullptr] = -1;
    index_n[-1] = nullptr;

    while (h->next)
    {
        h = h->next;
        r->next = new Node(h->val);
        r = r->next;
        n++;
        n_index[h] = n;
        index_n[n] = r;
    }
    r = res;
    h = head;
    while (h)
    {
        auto it_index = n_index.find(h->random);
        auto it_n = index_n.find(it_index->second);
        r->random = it_n->second;
        h = h->next;
        r = r->next;
    }
    return res;
}

int main()
{
    // [[1,1],[2,1]]
    Node*head=new Node(1);
    head->next=new Node(2);
    head->random=head->next;
    head->next->random=head->next;
    Node* res=copyRandomList(head);
    // cout << 1;
    return 0;
}
