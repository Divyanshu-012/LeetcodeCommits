class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
       
        ListNode* temp = head;
        int cnt = 0;
        while (temp != nullptr) {
            cnt++;
            temp = temp->next;
        }

        
        int equal = cnt / k;
        int extra = cnt % k;

        
        ListNode* current = head;
        vector<ListNode*>ans;

        while(k--){
            int t=equal;
           if(extra>0) t++;
            t--;
            ListNode* newHead=current;
            ListNode* temp=newHead;
            while(newHead && t--){
                newHead=newHead->next;
            }
            if(newHead){
                current=newHead->next;
                newHead->next=NULL;
            }
            ans.push_back(temp);
            extra--;
        }

        

        return ans;
    }
};
