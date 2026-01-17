class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        vector<int>store;
        for(int i= 1; i<=n;i++){
          store.push_back(i);
        }
        vector<int>fact(n+1,1);

        fact[0] = 1;

        for(int i = 1; i<=n;i++){
          fact[i] = fact[i-1] * i;
        }

        k = k-1;

        for(int i = n; i>=1;i--){
          int bs = fact[i-1];
          int idx = k/bs;

          string pick = to_string(store[idx]);

          ans += pick;
          store.erase(store.begin()+idx);
          k = k%bs;

        }
        return ans;

    }
};