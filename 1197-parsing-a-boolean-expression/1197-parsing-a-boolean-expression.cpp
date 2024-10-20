class Solution {
public:

    char solve(vector<char> &values, char op){
        if(op == '!'){
            return values[0] == 't' ? 'f' : 't';
        }

        if(op == '&'){
            for(auto ch : values){
                if(ch == 'f'){
                    return 'f';
                }
                
            }  
            return 't';

        }

        if(op == '|'){

            for(auto ch : values){
                if(ch == 't'){
                    return 't';
                }
                // return 'f';
            } 
            return 'f';

        }

        return 't'; // will never come here 
    }
    bool parseBoolExpr(string expression) {
        int n = expression.length();
        stack<char>st;

        for(int i = 0; i<n; i++){
            if(expression[i] == ',') 
                continue;
            if(expression[i]==')'){
                vector<char> values;

                while(st.top() != '('){
                    values.push_back(st.top());
                    st.pop();


                }

                st.pop();
                char op = st.top(); // !,&,|
                st.pop();

                st.push(solve(values,op));

            }   else{
                st.push(expression[i]);

            } 
            
        }
        return st.top() == 't' ? true : false;
        
    }
};