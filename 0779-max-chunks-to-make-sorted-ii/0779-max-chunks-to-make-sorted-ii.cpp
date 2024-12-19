class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> st;
        for(int i = 0; i < arr.size(); i++){
            int x = arr[i];
            while(!st.empty() && st.top() > arr[i]){
                x = max(x,st.top());
                st.pop();
            }
            st.push(x);
        }
        return st.size();
    }
};