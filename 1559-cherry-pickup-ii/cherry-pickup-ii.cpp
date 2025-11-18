class Solution {
public:
    vector<vector<vector<int>>> dp;
    vector<vector<int>> g;
    int n, m;
    int solve(int r, int c1, int c2) {
        if(c1 >= m || c2 >= m || c1 < 0 || c2 < 0)
            return -1e9;
        if(r >= n)
            return 0;
        if(dp[r][c1][c2] != -1e9)
            return dp[r][c1][c2];
        int maxi = max(solve(r + 1, c1 - 1, c2), solve(r + 1, c1, c2));
        maxi = max(maxi, solve(r + 1, c1 + 1, c2));
        maxi = max(maxi, solve(r + 1, c1, c2 - 1));
        maxi = max(maxi, solve(r + 1, c1, c2 + 1));
        maxi = max(maxi, solve(r + 1, c1 + 1, c2 + 1));
        maxi = max(maxi, solve(r + 1, c1 + 1, c2 - 1));
        maxi = max(maxi, solve(r + 1, c1 - 1, c2 + 1));
        maxi = max(maxi, solve(r + 1, c1 - 1, c2 - 1));
        maxi += g[r][c1];
        if(c1 != c2)
            maxi += g[r][c2];
        return dp[r][c1][c2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        g = grid;
        dp.resize(n, vector<vector<int>>(m, vector<int>(m, -1e9)));
        solve(0, 0, m - 1);
        return dp[0][0][m-1];
    }
};