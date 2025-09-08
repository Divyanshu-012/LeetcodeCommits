class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        
        vector<int> v;
        int count=0;

        bool flag=true;
        while(flag){
            n--;
                       
            count++;
            int num=n;
            
           while(num>0){
            int rem = num%10;
            if(rem==0)break;
            num/=10;
           }
           int val=count;
           while(val>0){
            int rem = val%10;
            if(rem==0)break;
            val/=10;
           }
           if(num==0 && val==0) flag=false;

        }
        
        v.push_back(count);
        v.push_back(n);
        return v;
    }
};