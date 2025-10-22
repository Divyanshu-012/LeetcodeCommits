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
    vector<int> getNLL(vector<int>& arr, int n) {
        vector<int> NLL(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) st.pop();

            if (st.empty()) NLL[i] = -1;       // no GREATER to left
            else NLL[i] = st.top();            // index of smaller element

            st.push(i);
        }
        return NLL;
    }

    vector<int> getNRR(vector<int>& arr, int n) {
        vector<int> NRR(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();

            if (st.empty()) NRR[i] = n;        // no smaller to right
            else NRR[i] = st.top();            // index of smaller element

            st.push(i);
        }
        return NRR;
    }
    long long subArrayRanges(vector<int>& arr) {
        int n = arr.size();
        vector<int> NSL = getNSL(arr, n);
        vector<int> NSR = getNSR(arr, n);
        vector<int> NLL = getNLL(arr, n);
        vector<int> NRR = getNRR(arr, n);

        long long Lsum = 0;
        long long Rsum = 0;
        // long long M = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            long long ls = i - NSL[i];     // elements to left where arr[i] is min
            long long rs = NSR[i] - i;     // elements to right where arr[i] is min

            long long totalWays = ls * rs; // total subarrays where arr[i] is min
            long long totalSum = (1LL * arr[i] * totalWays) ;

            Lsum = (Lsum + totalSum);
        }

        for (int i = 0; i < n; i++) {
            long long ll = i - NLL[i];     // elements to left where arr[i] is min
            long long rl = NRR[i] - i;     // elements to right where arr[i] is min

            long long totalWays = ll * rl; // total subarrays where arr[i] is min
            long long totalSum = (1LL * arr[i] * totalWays) ;

            Rsum = (Rsum + totalSum);
        }
        return Rsum - Lsum;
    }
};