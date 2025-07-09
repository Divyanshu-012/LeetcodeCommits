class Solution {
public:
    int mySqrt(int x) {
        int s = 0, e =x;
        
        while(s<=e){
            long long  mid = s + (e-s)/2;
            if((mid*mid)==x)return mid;
            if((mid*mid) > x)e=mid-1;
            if((mid*mid) < x)s=mid+1;
        }
        return e;
    }
}; 
    