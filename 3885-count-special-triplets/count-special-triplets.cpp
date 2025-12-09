class Solution {
public:
    const int M = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        auto func = [&] (const vector<int> &v) -> vector<int> {
            vector<int> dp(n, 0);
            unordered_map<int, int> mp;
            for(int i = n - 1; i >= 0; i--){ 
                int jval = nums[i];
                dp[i] = mp[jval << 1];
                mp[jval]++;
            }
            return dp;
        };
        vector<int> a = func(nums);
        reverse(nums.begin(), nums.end());
        vector<int> b = func(nums);
        reverse(b.begin(), b.end());
        int res = 0;
        for(int i = 0; i < n; i++)
            res = (res + 1LL*a[i]*b[i]) % M;
        return res;
    }
};