#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int M = 1e9 + 7;

    struct Nd {
        int maxi;
        int mini;
        int lo;
    };

    vector<Nd> st;
    vector<int> nums;
    int n;
    int ni;


    void build_tree(const vector<int>& a) {
        nums = a;
        n = (int)nums.size();
        ni = 1;
        while (ni < n) ni <<= 1;
        st.assign(2 * ni, { INT_MIN, INT_MAX, INT_MAX });

        for (int i = 1; i <= n; ++i) {
            int idx = ni + (i - 1);
            st[idx].maxi = nums[i - 1];
            st[idx].mini = nums[i - 1];
            st[idx].lo = i;
        }

        for (int v = ni - 1; v >= 1; --v) {
            st[v].maxi = max(st[2 * v].maxi, st[2 * v + 1].maxi);
            st[v].mini = min(st[2 * v].mini, st[2 * v + 1].mini);
            st[v].lo = (st[2 * v].lo != INT_MAX) ? st[2 * v].lo : st[2 * v + 1].lo;
        }
    }

    int range_max(int l, int r) {
        if (l > r) return INT_MIN;
        int L = ni + (l - 1);
        int R = ni + (r - 1);
        int res = INT_MIN;
        while (L <= R) {
            if (L & 1) res = max(res, st[L++].maxi);
            if (!(R & 1)) res = max(res, st[R--].maxi);
            L >>= 1; R >>= 1;
        }
        return res;
    }

    int range_min(int l, int r) {
        if (l > r) return INT_MAX;
        int L = ni + (l - 1);
        int R = ni + (r - 1);
        int res = INT_MAX;
        while (L <= R) {
            if (L & 1) res = min(res, st[L++].mini);
            if (!(R & 1)) res = min(res, st[R--].mini);
            L >>= 1; R >>= 1;
        }
        return res;
    }

    int climb(int pos, int k) {
        int lo = 1, hi = pos;
        while (lo < hi) {
            int mid = (lo + hi) >> 1;
            int mx = range_max(mid, pos);
            int mn = range_min(mid, pos);
            if ((long long)mx - (long long)mn <= k) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }

    int countPartitions(vector<int>& a, int k) {
        if (a.empty()) return 0;
        build_tree(a);

        vector<int> dp(n + 1, 0);
        vector<int> pref(n + 1, 0);
        dp[0] = 1;
        pref[0] = 1;

        for (int i = 1; i <= n; ++i) {
            int j = climb(i, k);
            long long total = pref[i - 1];
            long long subtract = (j - 2 >= 0) ? pref[j - 2] : 0;
            long long ways = (total - subtract) % M;
            if (ways < 0) ways += M;
            dp[i] = (int)ways;
            pref[i] = pref[i - 1] + dp[i];
            if (pref[i] >= M) pref[i] -= M;
        }

        return dp[n];
    }
};
