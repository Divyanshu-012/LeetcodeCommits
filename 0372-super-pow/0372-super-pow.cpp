constexpr int MOD = 1337;
class Solution {
private:
    int Pow(int base , int x){
        int res = 1;
        base %= MOD;
        while(x){
            if(x & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            x >>= 1;
        }
        return res;
    }
public:
    int superPow(int a, vector<int>& b) {
        if(b.empty()) return 1;
        int lastDigit = b.back(); b.pop_back();
        return Pow(superPow(a , b) , 10) * Pow(a , lastDigit) % MOD;
    }
};