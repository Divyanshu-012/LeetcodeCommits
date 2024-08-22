class Solution {
public:
    int findComplement(int num) {
        if (num == 0) return 1; // Special case for 0, whose complement is 1
        
        unsigned int mask = ~0; // Start with a mask of all 1s (e.g., 111...111)

        // Shift the mask left until it's just bigger than the number
        while (num & mask) {
            mask <<= 1;
        }

        // XOR the number with the inverse of the mask to get the complement
        return ~mask & ~num;
        
    }
};