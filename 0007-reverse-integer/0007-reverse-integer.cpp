class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        int n = s.size();
        long long   sum = 0;
        if(x>0){
            for(int i =0;i<n;i++){
            
                sum += (s[i]-'0')*pow(10,i);
            }
        }else{
            for(int i =1;i<n;i++){
            
                sum += (s[i]-'0')*pow(10,i-1);
            }
        }
         
        if(sum > INT_MAX) return 0;
        // if(sum < -10e9-1) return 0;
        return (x < 0)? -sum :sum;

        
    }
};