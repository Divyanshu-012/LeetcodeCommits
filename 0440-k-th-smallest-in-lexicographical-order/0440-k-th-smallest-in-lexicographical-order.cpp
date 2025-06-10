class Solution {
public:
    int Count(long curr,long next,int n){
        int cnt = 0;

        while(curr <=n){
            cnt +=  next - curr;
            curr *= 10;
            next*=10;

            if(next>n) next = min(next,long(n+1));
             
            
                
            
            
            
        }
        return cnt;

    }
    int findKthNumber(int n, int k) {
        int curr = 1;
        k=k-1; // as we already considering 1 as the 1st nunber , so k-1

        while(k > 0){
            int cnt = Count(curr,curr+1,n);
            if(cnt <= k){// skip the current tree
                curr+=1;
                k-=cnt;
            }else{
                curr*=10;
                k--;
            }
        }
        return curr;
    }
};