#include <queue>
#include <iostream>

using std::cout;
using std::endl;
using std::queue;
using std::unordered_map;
using std::vector;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;

        unordered_map<Node *, Node *> cloned;
        cloned[node] = new Node(node->val);

        queue<Node *> q;
        q.push(node);

        while (!q.empty())
        {
            Node *cur = q.front();
            q.pop();
            for (Node *nei : cur->neighbors)
            {
                if (!cloned.count(nei))
                {
                    cloned[nei] = new Node(nei->val);
                    q.push(nei);
                }
                cloned[cur]->neighbors.push_back(cloned[nei]);
            }
        }

        return cloned[node];
    }
};

int main()
{

    Solution s;

    return 0;
}