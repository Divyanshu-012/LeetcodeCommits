class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long exp = abs(static_cast<long long>(n));  // Use long long to handle the edge case where n is INT_MIN

        if(n<0) x = 1/x;
        
            while (exp > 0) {
            if (exp % 2 == 1) {  // If exp is odd, multiply ans by x
                ans = ans * x;
            }
            x = x * x;  // Square the base
            exp /= 2;   // Reduce exp by half
        }
        
        

      
      return ans;
        
    }
};