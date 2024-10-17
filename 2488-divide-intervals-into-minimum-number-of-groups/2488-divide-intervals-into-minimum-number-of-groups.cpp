class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // step 1
        sort(intervals.begin(), intervals.end());
        // step 2
        priority_queue<int, vector<int>, greater<int>> pq;


        // step 3 

        for(auto interval : intervals ){
            int start  = interval[0];
            int end = interval[1];

            if(!pq.empty() && start > pq.top()){
                pq.pop();
            }

            pq.push(end);

        }

        return pq.size();



    }
};