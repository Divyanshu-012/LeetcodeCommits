class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int>q;
        unordered_set<int>st(nums.begin(),nums.end());
        int n = st.size();
        
        int ans;

        for(auto i : st){
            q.push(i);
        }
        if(n < 3)return q.top();
        int k =3;
        while(k!=0){
            ans = q.top();
            q.pop();
            k--;
        }
        return ans;
    }
};