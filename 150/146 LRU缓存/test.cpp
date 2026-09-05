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

// 查找优化 unordered_map<int, myListNode> m;

struct myListNode
{
    int val;
    myListNode *next;
    myListNode *front;
    myListNode() : val(0), next(nullptr), front(nullptr) {}
    myListNode(int x) : val(x), next(nullptr), front(nullptr) {}
    myListNode(int x, myListNode *next, myListNode *front) : val(x), next(next), front(front) {}
};

class LRUCache
{
public:
    myListNode *head;
    myListNode *tail;
    unordered_map<int, int> m;
    int cnt;
    int total;
    LRUCache(int capacity)
    {
        head = new myListNode(0);
        cnt = 0;
        total = capacity;
        myListNode *t = head;
        for (int i = 1; i < capacity; i++)
        {
            t->front = new myListNode(0, t, nullptr);
            t = t->front;
        }
        tail = head;
        tail->next = new myListNode(0, nullptr, tail);
        t->front = new myListNode(0, t, nullptr);
    }

    int get(int key)
    {
        auto it = m.find(key);
        if (it == m.end())
            return -1;
        else
        {
            // 命中 维护
            if (head->val == key)
                return m[key];
            if (tail->val == key)
            {
                head->front = new myListNode(key, head, nullptr);
                head = head->front;
                tail = tail->front;
                return m[key];
            }
            myListNode *t = head;
            while (t)
            {
                if (t->val == key)
                    break;
                t = t->next;
            }
            t->front->next = t->next;
            t->next->front = t->front;
            head->front = new myListNode(key, head, nullptr);
            head = head->front;
            // tail=tail->front;
            // tail->next=nullptr;
            return m[key];
        }
    }

    void put(int key, int value)
    {
        auto it = m.find(key);
        if (it == m.end())
        {
            if (cnt < total)
            {
                if (!head->front)
                    head->front = new myListNode(0, head, nullptr);
                head = head->front;
                head->val = key;
                m[key] = value;
                cnt++;
                if (cnt == 1)
                    tail = tail->front;
            }
            else
            {
                // 缓存满  替换并维护
                m.erase(tail->val);
                m[key] = value;
                head->front = new myListNode(key, head, nullptr);
                head = head->front;
                tail = tail->front;
                // tail->next=nullptr;
            }
        }
        else
        {
            m[key] = value;
            // 在缓存中  维护
            if (head->val == key)
                return;
            if (tail->val == key)
            {
                head->front = new myListNode(key, head, nullptr);
                head = head->front;
                tail = tail->front;
                return;
            }
            myListNode *t = head;
            while (t)
            {
                if (t->val == key)
                    break;
                t = t->next;
            }
            t->front->next = t->next;
            t->next->front = t->front;
            head->front = new myListNode(key, head, nullptr);
            head = head->front;
            // tail=tail->front;
            // tail->next=nullptr;
        }
    }
};

int main()
{
    LRUCache lru(10);
    lru.put(7, 28);
    lru.put(7, 1);
    lru.put(8, 15);
    cout << endl;

    cout << lru.get(6);
    lru.put(10, 27);
    lru.put(8, 10);
    cout << lru.get(8);
    lru.put(6, 29);
    lru.put(1, 9);
    cout << endl;

    cout << lru.get(6);
    lru.put(10, 7);
    cout << lru.get(1);
    cout << lru.get(2);
    cout << lru.get(13);
    cout << endl;

    lru.put(8, 30);
    lru.put(1, 5);
    cout << lru.get(1);
    lru.put(13, 2);
    cout << lru.get(12);

    // cout << 1;
    return 0;
}
