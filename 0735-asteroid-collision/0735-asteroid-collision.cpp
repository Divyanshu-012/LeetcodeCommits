class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ass) {
        stack<int>st;
        vector<int>ans;
        for(int i = 0; i <ass.size();i++){
            if(ass[i] > 0) st.push(ass[i]);
            if(ass[i] < 0 && !st.empty()){
                while(!st.empty() && st.top() < abs(ass[i])) st.pop();
                if(st.empty()) ans.push_back(ass[i]);
                if(!st.empty() && st.top() == abs(ass[i])) {
                    st.pop();
                    continue;
                }    
            }
            else if (ass[i] < 0 && st.empty()){
                ans.push_back(ass[i]);
            }
            
        }
        vector<int>intermediate;
        while(!st.empty()){
            intermediate.push_back(st.top());
            st.pop();
        }
        for(int i =intermediate.size()-1; i>=0;i--){
            ans.push_back(intermediate[i]);
        }
        return ans;
    }
};