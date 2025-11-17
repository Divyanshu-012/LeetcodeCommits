class Solution {
public:
    int LIS(vector<int> arr){
        vector<int> st;
        int n = arr.size();
        for(int i=0; i<n; i++){
            auto it = upper_bound(st.begin(), st.end(), arr[i]);
            if(it == st.end()) st.push_back(arr[i]);
            else *it = arr[i];
        }  

        return st.size(); 
    }

    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size();
        int ret = 0;

        for(int start=0; start<k; start++){
            vector<int> v;
            for(int i=start; i<n; i+=k) v.push_back(arr[i]);
            ret = ret + v.size() - LIS(v);
        }
        return ret;
    }
};