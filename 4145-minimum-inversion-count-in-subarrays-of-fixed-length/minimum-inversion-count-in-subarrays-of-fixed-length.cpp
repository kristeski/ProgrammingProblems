#define ll long long
class Solution {
public:
    ll n, m;
    unordered_map<ll, ll> mp;
    vector<ll> bit;

    void up(ll pos, ll val) {
        while (pos <= n) {
            bit[pos] += val;
            pos += pos & -pos;
        }
    }
    ll qry(ll pos) {
        ll res = 0;
        while (pos >= 1) {
            res += bit[pos];
            pos -= pos & -pos;
        }
        return res;
    }

    long long minInversionCount(vector<int>& nums, int k) {
        set<ll> s(nums.begin(), nums.end());
        n = s.size(); bit.assign(n + 1, 0); m = nums.size();

        ll indx = 1, mini, tmp = 0;
        for (auto i : s) mp[i] = indx++;
        for (ll i = 0; i < k; i++) {
            ll val = nums[i];
            tmp += i - qry(mp[val]);
            up(mp[val], 1);
        }
        mini = tmp;
        for (ll i = k; i < m; i++) {
            ll val = nums[i], pval = nums[i - k];
            tmp -= qry(mp[pval] - 1);
            up(mp[pval], -1);
            tmp += k - qry(mp[val]) - 1;
            up(mp[val], 1);
            mini = min(mini, tmp);
        }
        return mini;
    }
};