class Solution {
public:

    char solve(vector<char> &values, char op){  // Change vector<int> to vector<char>
        if(op == '!'){
            return values[0] == 't' ? 'f' : 't';  // Fix type comparison with 't' and 'f'
        }

        if(op == '&'){
            for(auto ch : values){
                if(ch == 'f'){  // Check for 'f' correctly
                    return 'f';
                }
            }
            return 't';  // Return 't' if no 'f' is found
        }

        if(op == '|'){
            for(auto ch : values){
                if(ch == 't'){  // Check for 't' correctly
                    return 't';
                }
            }
            return 'f';  // Return 'f' if no 't' is found
        }

        return 't';  // Will never reach this point
    }

    bool parseBoolExpr(string expression) {
        int n = expression.length();
        stack<char> st;

        for(int i = 0; i < n; i++){
            if(expression[i] == ',') 
                continue;
            
            if(expression[i] == ')'){
                vector<char> values;

                while(st.top() != '('){
                    values.push_back(st.top());
                    st.pop();
                }

                st.pop(); // Remove '('
                char op = st.top(); // !,&,|
                st.pop();

                st.push(solve(values, op));  // Push the result back onto the stack

            } else {
                st.push(expression[i]);  // Push the current character onto the stack
            } 
        }

        return st.top() == 't' ? true : false;  // Final evaluation
    }
};
