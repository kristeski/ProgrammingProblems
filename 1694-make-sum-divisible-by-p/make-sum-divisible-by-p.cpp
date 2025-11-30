class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size(), mini = 1e5 + 1;
        vector<long long> pfs(n + 1), pfsmod(n + 1); pfs[0] = 0;
        unordered_map<int, vector<int>> mp;
        for (int i = 1; i <= n; i++) {
            int nindx = i - 1;
            pfs[i] = pfs[nindx] + nums[nindx];
            pfsmod[i] = pfs[i] % p;
            mp[pfsmod[i]].push_back(i);
        }
        if(!pfsmod[n]) return 0;
        for (int i = 1; i <= n; i++) {
            int nindx = i - 1;
            int f = (pfsmod[n] + pfsmod[nindx]) % p;
            auto it = lower_bound(mp[f].begin(), mp[f].end(), i);
            if(it != mp[f].end())
                mini = min(mini, mp[f][(int)(it - mp[f].begin())] - nindx);
        }
        if(mini == n)
            return -1;
        return mini;
    }


};