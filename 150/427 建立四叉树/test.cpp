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
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

Node *construct(vector<vector<int>> &grid)
{
    int l = grid.size();
    if (l == 1)
    {
        Node *r = new Node(grid[0][0], true);
        return r;
    }
    vector<vector<int>> grid1;
    vector<vector<int>> grid2;
    vector<vector<int>> grid3;
    vector<vector<int>> grid4;

    for (int i = 0; i < l / 2; i++)
    {
        vector<int> t;
        grid1.push_back(t);
        grid2.push_back(t);
        grid3.push_back(t);
        grid4.push_back(t);
        for (int j = 0; j < l / 2; j++)
        {
            grid1[i].push_back(grid[i][j]);
            grid2[i].push_back(grid[i][j + l / 2]);
            grid3[i].push_back(grid[i + l / 2][j]);
            grid4[i].push_back(grid[i + l / 2][j + l / 2]);
        }
    }
    Node *r1 = construct(grid1);
    Node *r2 = construct(grid2);
    Node *r3 = construct(grid3);
    Node *r4 = construct(grid4);

    if (r1->isLeaf && r2->isLeaf && r3->isLeaf && r4->isLeaf)
    {
        if (r1->val == r2->val && r2->val == r3->val && r3->val == r4->val)
        {
            Node *r = new Node(r1->val, true);
            return r;
        }
        else
        {
            Node *r = new Node(-1, false, r1, r2, r3, r4);
            return r;
        }
    }
    else
    {
        Node *r = new Node(-1, false, r1, r2, r3, r4);
        return r;
    }
}

int main()
{
    /* [[1,1,1,1,1,1,1,1],
        [1,1,1,1,1,1,1,1],
        [1,1,1,1,1,1,0,0],
        [1,1,1,1,1,1,0,0],
        [1,1,1,1,1,1,1,1],
        [1,1,1,1,1,1,1,1],
        [0,0,0,0,1,1,1,1],
        [0,0,0,0,1,1,1,1]]
    */
    
    cout << 1;
    return 0;
}
