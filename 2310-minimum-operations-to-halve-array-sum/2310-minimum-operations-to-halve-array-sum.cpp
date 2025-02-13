class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum=0.0;
        int n=nums.size();
        if (n==1)return 1;

        for (int i=0; i<n ;i++){
            sum=sum+nums[i];
        }

        priority_queue<double> pq;

        for (int i =0;i< n ;i++){
        pq.push(nums[i]);
        }

        int count=0;
        double   hsum=sum/2.0;

        while (pq.size()>0 && sum>hsum) {
        double  top=pq.top();
        
        pq.pop();
        top=top/2.0;
        sum=sum-top;
        pq.push(top);
        count++;

       }
       return count;
        
    }
};