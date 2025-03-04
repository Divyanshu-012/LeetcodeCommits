class Solution {
public:
    bool matchesP(string &num , string &p){
        for(int i = 0 ; i< p.length(); i++){
            if( (p[i] == 'I' && num[i] > num[i+1] ) || (p[i] == 'D' && num[i] < num[i+1])){
                return false;
            }
        }

        return true;
    }
    string smallestNumber(string p) {
        int n = p.length();
        string num = "";

        for(int i = 1; i<= n+1; i++){
            num.push_back( i +'0');
        }

        while(!matchesP(num,p)){
            next_permutation(begin(num),end(num));
        }

        return num;
    }
};