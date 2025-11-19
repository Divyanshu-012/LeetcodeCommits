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
    ListNode*head;
    Solution(ListNode* head) {
        this->head=head;
    }
    
    int getRandom() {
        int size=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            size++;
            temp=temp->next;
        }
        int idx=rand()%size;
        temp=head;
        while(idx>0){
            idx--;
            temp=temp->next;
        }
        return temp->val;
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */