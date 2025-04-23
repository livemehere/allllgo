#include <set>

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
   public:
       bool hasCycle(ListNode *head) {
           if(head == nullptr || head->next == nullptr) return false;
            std::set<ListNode*> s;

            ListNode* cur = head;
            while(cur != nullptr){
                if(s.find(cur) != s.end()) return true;
                s.insert(cur);
                cur = cur->next;
            }
            return false;
        
         
       }
   };