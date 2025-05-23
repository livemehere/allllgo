 
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };
class Solution {
    public:
        bool hasCycle(ListNode *head) {
            if(head == nullptr || head->next == nullptr) return false;
            
            ListNode* slow = head;
            ListNode* fast = head->next;
            while(slow != fast){

                if(slow == nullptr || fast == nullptr) return false;

                slow = slow->next;
                fast = fast->next;
                if(fast != nullptr){
                    fast = fast->next;
                }
                
            }
            return true;
        }
    };