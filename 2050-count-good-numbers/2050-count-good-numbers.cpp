#define mod 1000000007

class Solution {
public:
    
    long long modPow(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            
            
            if (exp % 2 == 1) { 
                result = (result * base) % mod;  
            }
            base = (base * base) % mod;  
            exp /= 2;  
            
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
