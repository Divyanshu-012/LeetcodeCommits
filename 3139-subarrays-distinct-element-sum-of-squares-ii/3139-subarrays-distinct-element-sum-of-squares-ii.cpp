#define intt long long
const int mod = 1e9 + 7;

class Solution {
    vector<intt> sum, sq, lazy;
    void apply(int v, int l, int r, int x) {
        sq[v] += 2ll * sum[v] * x + (r - l + 1) * x * x * 1ll;
        sum[v] += (r - l + 1) * x;
        sq[v] %= mod;
        sum[v] %= mod;
    }
    void push(int v, int l, int r) {
        if (l != r and lazy[v]) {
            lazy[v * 2] += lazy[v];
            lazy[v * 2 + 1] += lazy[v];
            int m = (l + r) / 2;
            apply(v * 2, l, m, lazy[v]);
            apply(v * 2 + 1, m + 1, r, lazy[v]);
            lazy[v] = 0;
        }
    }
    void upd(int v, int l, int r, int ul, int ur) {
        if (ul <= l and r <= ur) {
            apply(v, l, r, 1);
            lazy[v]++;
            return;
        }
        push(v, l, r);
        int m = (l + r) / 2;
        if (ul <= m) {
            upd(v * 2, l, m, ul, ur);
        }
        if (m < ur) {
            upd(v * 2 + 1, m + 1, r, ul, ur);
        }
        sum[v] = sum[v * 2] + sum[v * 2 + 1];
        sq[v] = sq[v * 2] + sq[v * 2 + 1];
        sq[v] %= mod;
        sum[v] %= mod;
    }
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size(), m = 0;
        vector<int> a(1);
        for (int i : nums) {
            m = max(m, i);
            a.push_back(i);
        }
        sum.resize(4 * n + 4);
        lazy.resize(4 * n + 4);
        sq.resize(4 * n + 4);
        vector<int> last(m + 1);
        intt res = 0;
        for (int i = 1; i <= n; i++) {
            upd(1, 1, n, last[a[i]] + 1, i);
            last[a[i]] = i;
            res += sq[1];
            res %= mod;
        }
        return res;
    }
};