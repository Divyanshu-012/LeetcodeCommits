#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;
    unordered_map<ll, ll> mp; // total damage per unique power
    vector<ll> nums;
    vector<ll> dp;
    int n;

    ll solve(int idx) {
        if (idx >= n) return 0;
        if (dp[idx] != -1) return dp[idx];

        ll val = nums[idx];
        ll take = mp[val]; // total damage for this spell type

        // find next index that is safe to take (diff > 2)
        int nextIdx = idx + 1;
        while (nextIdx < n && nums[nextIdx] <= val + 2)
            nextIdx++;

        // 2 choices: take or skip
        ll include = take + solve(nextIdx);
        ll exclude = solve(idx + 1);

        return dp[idx] = max(include, exclude);
    }

    long long maximumTotalDamage(vector<int>& power) {
        mp.clear();
        for (auto p : power) mp[p] += p; // store total damage per power

        for (auto& it : mp) nums.push_back(it.first);
        sort(nums.begin(), nums.end());
        n = nums.size();
        dp.assign(n, -1);

        return solve(0);
    }
};
