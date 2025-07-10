class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& st, vector<int>& et) {
        int n = st.size();
        vector<int>freeArray;
        if(st[0]!=0){
            
            freeArray.push_back(st[0]);
        }
        for(int i =1;i<n;i++){
            freeArray.push_back(st[i]-et[i-1]);
        }
        if(et[n-1]!= eventTime){
            freeArray.push_back(eventTime- et[n-1]);
        }

        int i =0;
        int j =0;
        int mxSum =0;
        int cSum=0;

        int m = freeArray.size();
        while(j<m){
            cSum += freeArray[j];

            while(i<m && j-i+1 > k+1){
                cSum -= freeArray[i];
                i++;
            }
            mxSum = max(mxSum,cSum);
        j++;
        }

        return mxSum;
    }
    
};