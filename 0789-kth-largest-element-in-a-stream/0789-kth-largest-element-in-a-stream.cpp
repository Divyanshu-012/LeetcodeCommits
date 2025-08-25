class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq; // min-heap of size k

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) pq.pop(); // keep only k largest elements
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > k) pq.pop(); // maintain size k
        return pq.top(); // kth largest element
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */