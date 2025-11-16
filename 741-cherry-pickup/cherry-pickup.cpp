class Solution {
public:
    vector<vector<vector<int>>> dp;
    vector<vector<int>> g;
    int n;

    int solve(int r1, int c1, int c2) {
        int r2 = r1 + c1 - c2;
        if (r1 >= n || r2 >= n || c1 >= n || c2 >= n) return -1e9;
        if (dp[r1][c1][c2] != INT_MIN) return dp[r1][c1][c2];
        if (g[r1][c1] == -1 || g[r2][c2] == -1) return dp[r1][c1][c2] = -1e9;
        if (r1 == n-1 && c1 == n-1) return dp[r1][c1][c2] = g[r1][c1];

        int maxi = max(solve(r1 + 1, c1, c2), solve(r1, c1 + 1, c2));
        maxi = max(maxi, solve(r1 + 1, c1, c2 + 1));
        maxi = max(maxi, solve(r1, c1 + 1, c2 + 1));
        if (maxi == -1e9)
            return dp[r1][c1][c2] = -1e9;
        maxi += g[r1][c1];
        if(r1 != r2)
            maxi += g[r2][c2];
        return dp[r1][c1][c2] = maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        g = grid;
        n = grid.size();
        dp.assign(n, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        if (grid[0][0] == -1) return 0;
        int ans = solve(0, 0, 0);
        if (ans < 0) return 0;
        return ans;
    }
};
