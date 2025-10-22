class Solution {
public:
    vector<int> getNSL(vector<int>& arr, int n) {
        vector<int> NSL(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();

            if (st.empty()) NSL[i] = -1;       // no smaller to left
            else NSL[i] = st.top();            // index of smaller element

            st.push(i);
        }
        return NSL;
    }

    vector<int> getNSR(vector<int>& arr, int n) {
        vector<int> NSR(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();

            if (st.empty()) NSR[i] = n;        // no smaller to right
            else NSR[i] = st.top();            // index of smaller element

            st.push(i);
        }
        return NSR;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> NSL = getNSL(arr, n);
        vector<int> NSR = getNSR(arr, n);

        long long sum = 0;
        long long M = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            long long ls = i - NSL[i];     // elements to left where arr[i] is min
            long long rs = NSR[i] - i;     // elements to right where arr[i] is min

            long long totalWays = ls * rs; // total subarrays where arr[i] is min
            long long totalSum = (1LL * arr[i] * totalWays) % M;

            sum = (sum + totalSum) % M;
        }
        return sum;
    }
};
