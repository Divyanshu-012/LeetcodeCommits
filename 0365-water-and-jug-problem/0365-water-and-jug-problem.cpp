class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if (target > x + y) return false;
        if (target == 0) return true;
        if (x == 0) return target == y;
        if (y == 0) return target == x;

        return target % std::gcd(x, y) == 0;
    }
};