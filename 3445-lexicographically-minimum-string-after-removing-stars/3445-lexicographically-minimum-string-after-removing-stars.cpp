class Solution {
public:
    struct comp{
            bool operator()(pair<char,int>&p1,pair<char,int>&p2 ){
                if(p1.first==p2.first){
                    return p1.second <p2.second;
                }
                return p1.first >p2.first;
            }
            
        };
    string clearStars(string s) {
        priority_queue<pair<char,int>,vector<pair<char,int>>,comp>pq; //minheap
        int n = s.size();

        for(int i =0  ; i<n;i++){
            if(s[i] != '*'){
                pq.push({s[i],i});
            }
            else{
                int idx = pq.top().second;
                pq.pop();
                s[idx] = '*';
            }
        }

        string result = "";
        for(int i =0; i< n; i++){
            if(s[i]!='*'){
                result.push_back(s[i]);
            }
        }
        return result;
    }
};