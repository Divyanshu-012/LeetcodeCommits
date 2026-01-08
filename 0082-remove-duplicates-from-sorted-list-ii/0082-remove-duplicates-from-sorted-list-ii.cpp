/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;
        
        while(curr){
            int value = curr->val;
            if(curr->next && curr->next->val == value){
                while(curr && curr->val == value){
                    prev->next = curr->next;
                    curr = curr->next;
                }
            }else{
                curr=curr->next;
                prev=prev->next;
            }
        }
        return dummy->next;
    }
};