class Solution {
public:
// XOR (^) gives the sum without carry.

// AND (&) followed by a left shift (<< 1) gives the carry.
    int getSum(int a, int b) {
        while(b != 0){
            unsigned carry = (unsigned)(a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};