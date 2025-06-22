class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        
        string cur = "";
        for(int i=0;i<s.size();i++){
            cur += s[i];

            if(cur.size() == k){
                ans.push_back(cur);
                cur = ""; 
            }
        }

        if(cur != ""){
           
            while(cur.size() < k){
                
                cur += fill;
            }
            ans.push_back(cur);
        }

        return ans;
    }
};