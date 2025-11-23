class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(3, -1e9));
        dp[0][nums[0]%3] = nums[0];
        for(int i = 1; i < n; i++) {
            int ost = nums[i] % 3;
            for(int j = 0; j < 3; j++) {
                int x = (3 + j - ost) % 3;
                dp[i][j] = max(dp[i - 1][x] + nums[i], dp[i-1][j]);
                if(dp[i][j] < 0)
                    dp[i][j] = -1e9;
            }
            dp[i][ost] = max(dp[i][ost], nums[i]);
        }
        if(dp[n-1][0] == -1e9)
            return 0;
        return dp[n - 1][0];
    }
};