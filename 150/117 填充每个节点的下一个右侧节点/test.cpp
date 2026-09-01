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
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node *connect(Node *root)
{
    queue<Node *> q1;
    queue<int> q2;
    q1.push(root);
    q2.push(1);
    while (!q1.empty())
    {
        Node *t = q1.front();
        int l = q2.front();
        q1.pop();
        q2.pop();
        if (t)
        {
            q1.push(t->left);
            q1.push(t->right);
            q2.push(l + 1);
            q2.push(l + 1);
        }

        Node *f = t;
        while(!q1.empty())
        {
            if(q2.front()==l)
            {
                t=q1.front();
                q1.pop();
                q2.pop();
                if (t)
                {
                    q1.push(t->left);
                    q1.push(t->right);
                    q2.push(l + 1);
                    q2.push(l + 1);
                }
                if(!f)
                {
                    f=t;
                }
                else
                {
                    if(t)
                    {
                        f->next=t;
                        f=t;
                    }
                }
            }
            else
                break;
        }
    }
    return root;
}

int main()
{
    // 3,9,20,15,7
    // 9,3,15,20,7
    // 9,15,7,20,3
    //      1
    //    2    3
    //  4  5    7
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);
    root = connect(root);
    cout << 1;

    return 0;
}
