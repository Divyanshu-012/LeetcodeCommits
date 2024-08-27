#define mod 1000000007

class Solution {
public:
    // Function to perform modular exponentiation
    long long modPow(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            
            
            if (exp % 2 == 1) { 
                result = (result * base) % mod;  // If exp is odd, multiply the base with the result
            }
            base = (base * base) % mod;  // Square the base
            exp /= 2;  // Divide the exponent by 2
            
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long numberOfOddPlaces = n / 2;
        long long numberOfEvenPlaces = n / 2 + n % 2;

        long long evenResult = modPow(5, numberOfEvenPlaces);
        long long oddResult = modPow(4, numberOfOddPlaces);

        // Perform modulo operation after multiplication to prevent overflow
        return (evenResult * oddResult) % mod;
    }
};
