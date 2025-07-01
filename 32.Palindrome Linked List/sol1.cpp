#include <vector>
#include <string>
#include <sstream>

using namespace std;

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
    bool isPalindrome(ListNode *head)
    {
        vector<int> res;
        ListNode *cur = head;
        while (cur)
        {
            res.push_back(cur->val);
            cur = cur->next;
        }

        string res_str = join_str(res);

        vector<int> resersed_res;
        copy(res.rbegin(), res.rend(), back_inserter(resersed_res));
        string reverse_str = join_str(resersed_res);

        return res_str == reverse_str;
    }

    string join_str(vector<int> vec)
    {
        ostringstream oss;
        for (int val : vec)
        {
            oss << to_string(val);
        }
        return oss.str();
    }
};