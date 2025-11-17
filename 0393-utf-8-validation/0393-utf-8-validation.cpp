class Solution {
public:
    bool validUtf8(vector<int>& data) {    
        int more = 0;
        for (auto& c : data) {
            if (more && (c >> 6 != 2)) return false;
            else if (more--) continue;
            else if ((c >> 7) == 0) more = 0;
            else if ((c >> 5) == 6) more = 1;
            else if ((c >> 4) == 14) more = 2;
            else if ((c >> 3 == 30)) more = 3;
            else return false;

        }
        return more == 0;
    }
};