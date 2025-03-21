class Solution {
public:

    bool check(int i, int currsum , string s , int num){
        if(i == s.length()){
            return currsum == num;
        }

        if(currsum > num){
            return false;
        }

        // bool possible = false;

        for(int j = i ; j< s.length(); j++){
            string sub = s.substr(i, j-i+1);
            int val = stoi(sub);

            if(check(j+1, currsum+val, s, num)== true) return true;

            // if(possible == true){
            //     return true ;
            // }
        }
        return false;
    }


    int punishmentNumber(int n) {
        int punish  = 0; 

        for (int num = 1 ; num <= n ; num++){
            int sq = num*num;

            string s = to_string(sq);

            if(check(0,0,s,num) == true){ // index, current sum , string s,  target  number 
                punish += sq;
            }
        }
        return punish;
    }
};