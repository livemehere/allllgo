#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode* root = new ListNode(0,nullptr);
            ListNode* cur = root;

            while(list1 && list2){
                if(list1->val < list2->val){
                    cur->next = list1;
                    list1 = list1->next;
                }else{
                    cur->next = list2;
                    list2 = list2->next;
                }
                cur = cur->next;
            }

            cur->next = (list1 == nullptr) ? list2 : list1;
            return root->next;
        }
    };

int main(){

    return 0;
}