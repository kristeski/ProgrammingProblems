class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(3, -1e9);
        for(int i : nums) {
            vector<int> ndp = dp;
            int r = i % 3;
            for(int j = 0; j < 3; j++) {
                int x = (3 + j - r) % 3;
                ndp[j] = max(ndp[j], dp[x] + i);
                if(ndp[j] < 0) ndp[j] = -1e9;
            }
            ndp[r] = max(ndp[r], i);
            dp.swap(ndp);
        }
        switch(dp[0]) {
            case (int)-1e9:
                return 0;
            default:
                return dp[0];
        }
    }
};