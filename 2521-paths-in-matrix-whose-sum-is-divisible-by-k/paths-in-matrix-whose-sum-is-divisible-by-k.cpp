class Solution {
public:
    vector<vector<vector<int>>> dp;
    //dp[i][j][k] = broj na patista do pozicija[i][j] vo matricata so ost p d s k k
    int n, m;
    const int M = 1e9 + 7;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n = grid.size(), m = grid[0].size();
        dp.resize(n, vector<vector<int>>(m, vector<int>(k, 0)));
        dp[0][0][grid[0][0] % k] = 1;
        int i;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int mom = grid[i][j] % k;
                for(int o = 0; o < k; o++) {
                    int ost = (o + mom) % k;
                    if(i) dp[i][j][ost] = (dp[i][j][ost] + dp[i - 1][j][o]) % M;
                    if(j) dp[i][j][ost] = (dp[i][j][ost] + dp[i][j - 1][o]) % M;
                }
            }
        }
        return dp[n-1][m-1][0];        
    }
};