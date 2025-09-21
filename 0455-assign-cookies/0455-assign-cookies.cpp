class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());

        int cnt = 0;
        int  j = 0; //greed index
        int i = 0; // size index

        while(i < s.size() && cnt < g.size()){
            if(s[i] >= g[j]){
                cnt++;
                j++;
            }
            i++;
        }
        return cnt;
    }
};