class Solution {
public:
    long long flowerGame(int n, int m) {
        int cnt = 0;
        if(n == 0 || m == 0 || (n == 1 && m == 1)) return 0;

        return 1LL*((n+1)/2)*(m/2) +1LL* ((m+1)/2)*(n/2);
    }
};