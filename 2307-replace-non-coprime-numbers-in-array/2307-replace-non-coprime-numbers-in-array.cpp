class Solution {
public:
    long long lcm(long long a,long long b){
        return a*b/gcd(a,b);
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<long long>st;
        for(int num:nums){
            long long current=num;
            while(!st.empty()){
                long long top=st.top();
                long long g=gcd(top,current); 
                if(g==1) break;
                st.pop();
               current= lcm(top,current);
            }
            st.push(current);
        }
        vector<int>result(st.size());
            for(int i=st.size()-1;i>=0;--i){
                result[i]=st.top();
                st.pop();
            }
            return result;
    }
};