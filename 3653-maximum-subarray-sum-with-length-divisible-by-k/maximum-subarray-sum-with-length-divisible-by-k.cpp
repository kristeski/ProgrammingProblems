class Solution {
public:
    const long long NEG = -100000000000000000;
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<long long> pfs(n + 1), dp(n + 1);
        long long maxi = NEG;
        pfs[0] = dp[0] = 0;
        for(int i = 1; i <= n; i++) 
            pfs[i] = pfs[i - 1] + nums[i - 1];
        for(int i = 1; i < k; i++)
            dp[i] = NEG;
        for(int i = k; i <= n; i++) {
            long long one = pfs[i] - pfs[i - k];
            dp[i] = max(dp[i - k] + one, one);
        }
        for(int i = 1; i <= n; i++) 
            maxi = max(maxi, dp[i]);
        
        return maxi;
    }
};