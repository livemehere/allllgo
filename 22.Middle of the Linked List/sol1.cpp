struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        int prev = 0;
        ListNode *cur = head;
        while (cur != nullptr)
        {
            ListNode *postNode = getNextNodeFrom(cur, prev);
            ListNode *postPostNode = getNextNodeFrom(cur, prev + 1);
            if (postNode == nullptr || postPostNode == nullptr)
                return cur;
            prev++;
            cur = cur->next;
        }
        return cur;
    }

    ListNode *getNextNodeFrom(ListNode *node, int step)
    {
        ListNode *cur = node;
        while (step > 0)
        {
            step--;
            cur = cur->next;
            if (cur == nullptr)
                return nullptr;
        }
        return cur;
    }
};