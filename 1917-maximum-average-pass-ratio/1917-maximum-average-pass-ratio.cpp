class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
        auto gain = [&](int pass, int total){
            return (double)(pass+1)/(total+1) - (double)pass/total;
        };

        priority_queue<pair<double,pair<int,int>>> pq;

        for(int i=0;i<classes.size();i++){
            int pass = classes[i][0];
            int total = classes[i][1];
            pq.push({gain(pass,total),{pass,total}});
        }

        while(extraStudents--){
            auto it = pq.top();
            pq.pop();
            int pass = it.second.first;
            int total = it.second.second;
            pass++;
            total++;
            pq.push({gain(pass,total),{pass,total}});
        }

        double ans = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            ans += (double)it.second.first/it.second.second;
        }

        return ans/(double)classes.size();
    }
};
