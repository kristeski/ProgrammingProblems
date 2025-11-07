class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        //RiciBoss
        int n = dungeon.size();
        int m = dungeon[0].size();
        const int INF = 1e9;
        vector<int> dp(m + 1, INF);
        dp[m - 1] = 1;            

        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                int need = min(dp[j], dp[j + 1]) - dungeon[i][j];
                dp[j] = max(1, need);
            }
        }
        return dp[0];
    }
};