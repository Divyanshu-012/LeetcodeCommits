class Solution {
public:
    int findComplement(int num) {
        long answer = 0;
        long pow = 1;

        while(num){
            answer+=(num%2==0) ? pow :0;
            num/=2;
            pow*=2;
        }
        return answer;
    }
};