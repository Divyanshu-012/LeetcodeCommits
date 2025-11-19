class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n<=0) return 0;
        if(n==1) return 1;
        vector<int> p(primes.size(),0);
        vector<long long> vec(n);
        vec[0]=1;
        
        int index=0;
        for(int i=1;i<n;i++){
            long long next = LLONG_MAX;
            for(int j=0;j<primes.size();j++){
                if(next>vec[p[j]]*primes[j]){
                    next=vec[p[j]]*primes[j];
                }   
            }
            vec[i]=next;
            for(int j=0;j<primes.size();j++){
                if(vec[i]==vec[p[j]]*primes[j]){
                    p[j]++;
                }   
            }
            vec[i]=next;
            }
            return vec[n-1];
    }
};