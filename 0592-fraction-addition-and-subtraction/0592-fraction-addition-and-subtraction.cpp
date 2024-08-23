class Solution {
public:
    string fractionAddition(string expression) {
        int numerator = 0, denominator = 1; // Initial fraction is 0/1
        
        int i = 0, n = expression.size();
        while (i < n) {
            // Read the sign
            int sign = 1;
            if (expression[i] == '+' || expression[i] == '-') {
                sign = expression[i] == '+' ? 1 : -1;
                i++;
            }
            
            // Read the numerator
            int currentNumerator = 0;
            while (i < n && isdigit(expression[i])) {
                currentNumerator = currentNumerator * 10 + (expression[i] - '0');
                i++;
            }
            currentNumerator *= sign;
            
            // Skip the '/'
            i++;
            
            // Read the denominator
            int currentDenominator = 0;
            while (i < n && isdigit(expression[i])) {
                currentDenominator = currentDenominator * 10 + (expression[i] - '0');
                i++;
            }
            
            // Update the result fraction
            numerator = numerator * currentDenominator + currentNumerator * denominator;
            denominator *= currentDenominator;
            
            // Simplify the fraction
            int gcd = std::gcd(abs(numerator), denominator);
            numerator /= gcd;
            denominator /= gcd;
        }
        
        return std::to_string(numerator) + "/" + std::to_string(denominator);
        
    }
};