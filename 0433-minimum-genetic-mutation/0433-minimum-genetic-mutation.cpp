class Solution {
public:
    int minMutation(string s, string e, vector<string>& bank) {
        unordered_set<string>st(bank.begin(),bank.end());

         unordered_set<string>vis;

        queue<string>q;

        q.push(s);
        vis.insert(s);

        int level = 0;

        while(!q.empty()){
            int n = q.size();

            while(n--){
                string curr = q.front();
                q.pop();

                if(curr == e) return level;

                for(char ch : "ACGT"){
                    for(int i= 0;i<curr.length();i++){
                        string nei = curr;
                        nei[i] = ch;

                        if(vis.find(nei) == vis.end() &&
                        st.find(nei)!=st.end()){
                            vis.insert(nei);
                            q.push(nei);
                        }
                    }
                }
            } 
            level++;
        }
        return -1;
    }
};