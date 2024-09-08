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
        int rem = cnt % k;

        
        vector<ListNode*> res(k,NULL);
        ListNode* current = head;
        
        for (int i = 0; i < k; i++) {
            if (current == NULL) break; 
            res[i] = current;
            int part_size = equal;
            if (rem > 0) {
                part_size++; 
                rem--;
            }
            for (int j = 1; j < part_size; j++) {
                current = current->next;
            }
            ListNode* next = current->next;
            current->next = NULL;
            current = next;
        }
        return res;
    }
};
