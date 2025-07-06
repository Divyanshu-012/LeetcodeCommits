class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> x;
        int a, b;
        for (auto i : tokens) {
            if (i != "+" && i != "-" && i != "*" && i != "/") {
                x.push(i);
            } else {
                a = stoi(x.top()); x.pop();
                b = stoi(x.top()); x.pop();
                if (i == "+") x.push(to_string(b + a));
                else if (i == "-") x.push(to_string(b - a));
                else if (i == "*") x.push(to_string(b * a));
                else if (i == "/") x.push(to_string(b / a));
            }
        }
        return stoi(x.top());
    }
};