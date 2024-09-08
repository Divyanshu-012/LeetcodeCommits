class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // Step 1: Count the number of nodes
        ListNode* temp = head;
        int cnt = 0;
        while (temp != nullptr) {
            cnt++;
            temp = temp->next;
        }

        // Step 2: Calculate the size of each part
        int partSize = cnt / k;
        int extra = cnt % k;

        vector<ListNode*> result(k, nullptr);
        ListNode* current = head;

        for (int i = 0; i < k && current != nullptr; i++) {
            result[i] = current;
            int currentPartSize = partSize + (extra-- > 0 ? 1 : 0);

            for (int j = 1; j < currentPartSize; j++) {
                current = current->next;
            }
            ListNode* nextPart = current->next;
            current->next = nullptr;
            current = nextPart;
        }

        return result;
    }
};
