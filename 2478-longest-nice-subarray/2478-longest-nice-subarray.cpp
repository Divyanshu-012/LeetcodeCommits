class Solution {
public:
    int longestNiceSubarray(vector<int>& v) {
        long n=v.size(),start=0,end=0,ans=0,cnt=0,s=0;
        while(end<n){
            s+=v[end];
            cnt = cnt | v[end];
            int curr = v[end++];
            int mask=0;
            while(s>cnt){
                s-=v[start];
                cnt -= v[start];
                if(curr & v[start]){
                    int toAdd = (curr & v[start]);
                    if(mask & toAdd){
                        toAdd = toAdd & (~mask);
                    }
                    cnt+=toAdd;
                    mask  |= toAdd;
                }
                start++;
            }
            ans=max(ans,end-start);
        }
        return ans;
    }
};