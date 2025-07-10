class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        long long sum=0;
        for(int i=0;i<32;i++){
            if((1LL<<(31-i))&n){
                sum+=(1LL<<i);
            }
        }
        return sum;
    }
};