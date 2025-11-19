class Solution {
public:
    vector<string> res;
    string cur;

    void dfs(string &s, int target, int pos, long long curVal, long long lastVal)
    {
        int n = s.size();
        if(pos == n && curVal == target)
        {
            res.push_back(cur);
            return;
        }
        if(pos >= n)
            return;

        long long val = 0;
        for(int i = pos; i<n; i++)
        {
            val = 10*val + (s[i] - '0');

            if(i>pos && s[pos] == '0')
                return;
            
            int old = cur.size();
            string part = s.substr(pos, i-pos+1);

            if(pos == 0)
            {
                cur += part;
                dfs(s, target, i+1, val, val);
                cur.resize(old);
            }
            else
            {
                // +
                cur += '+';
                cur += part;
                dfs(s, target, i+1, curVal+val, val);
                cur.resize(old);

                // -
                cur += '-';
                cur += part;
                dfs(s, target, i+1, curVal-val, -val);
                cur.resize(old);

                // * 
                cur += '*';
                cur += part;
                dfs(s, target, i+1, curVal - lastVal + lastVal * val, lastVal * val);
                cur.resize(old);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        if (num.empty()) return res;
        dfs(num, target, 0, 0, 0);
        return res;
    }
};