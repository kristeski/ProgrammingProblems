class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        while(m--) {
            vector<int> ndp = dp;
            for(int i = 1; i < n; i++) 
                ndp[i] += ndp[i-1];
            
            dp.swap(ndp);
        }
        return dp[n - 1];
    }
};