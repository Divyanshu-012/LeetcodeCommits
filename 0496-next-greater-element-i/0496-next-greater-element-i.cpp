class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        stack<int>st;
        int n = nums2.size();
        for(int i = n-1; i>=0; i--){
            
            while(!st.empty()){
                if(st.top() > nums2[i]){
                    mp[nums2[i]] = st.top();
                    st.push(nums2[i]);
                    break;
                }else{
                    st.pop();
                }
            }
            if(st.empty() ){
                mp[nums2[i]] = -1;
                st.push(nums2[i]);
            }

        }
        int i =0;

        int m = nums1.size();
        while(i<m){
            nums1[i] = mp[nums1[i]];
            i++;
        }
        return nums1;
            
        
    }
};