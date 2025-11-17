class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
     int prev = pref[0];

    for(int i = 1; i < pref.size(); i++){
        pref[i] = pref[i] ^ prev;
        prev = prev ^ pref[i];
    }
    return pref;
    }
};