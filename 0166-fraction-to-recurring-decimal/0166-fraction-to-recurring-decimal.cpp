class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) return "0";

    string result;
    // handle negative
    if ((numerator < 0) ^ (denominator < 0)) result += "-";

    long long n = llabs((long long)numerator);
    long long d = llabs((long long)denominator);

    result += to_string(n / d);  // integer part
    long long rem = n % d;

    if (rem == 0) return result;  // no decimals

    result += ".";
    unordered_map<long long, int> seen; // remainder -> index in result

    while (rem != 0) {
        if (seen.count(rem)) {
            result.insert(seen[rem], "(");
            result += ")";
            break;
        }
        seen[rem] = result.size();
        rem *= 10;
        result += to_string(rem / d);
        rem %= d;
    }
    return result;
}

};