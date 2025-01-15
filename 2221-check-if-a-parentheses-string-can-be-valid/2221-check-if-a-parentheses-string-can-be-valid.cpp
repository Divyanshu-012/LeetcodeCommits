class Solution {
public:
    bool canBeValid(string s, string l) {
        int n = s.size();
       
        if (n % 2 == 1) {
            return false;
        }
        stack<int>open;
        stack<int>OC;
        for(int i = 0 ; i< n;i++){
            if(l[i] == '0') OC.push(i);
            else if(s[i] == '(' ){
                open.push(i);
            }
            else if(s[i] == ')'){
                if(open.size() > 0){
                    open.pop();
                }
                else if (!OC.empty()){
                    OC.pop();
                }
                else return false;
                
            }
    
        }

        
        while(!open.empty() && !OC.empty() && open.top() < OC.top()){
            open.pop();
            OC.pop();

        }

        return open.empty();
    }
};