class Solution {
public:
    int n, m, s, e, ee;
    vector<int> moves;
    vector<vector<int>> g, dp;

    int f(int i, int j) { return i * m + j; }
    pair<int, int> f1(int l) { return { l / m, l % m }; }
    bool b(int i, int j) { return (i >= 0 && j >= 0 && i < n && j < m && g[i][j] != -1); }
    void mov(pair<int, int> p, int mask) {
        int i = p.first, j = p.second, tmp;
        fill(moves.begin(), moves.end(), -1);
        tmp = f(i + 1, j);
        if (b(i + 1, j) && (mask & (1 << tmp)))
            moves[0] = tmp;
        tmp = f(i - 1, j);
        if (b(i - 1, j) && (mask & (1 << tmp)))
            moves[1] = tmp;
        tmp = f(i, j + 1);
        if (b(i, j + 1) && (mask & (1 << tmp)))
            moves[2] = tmp;
        tmp = f(i, j - 1);
        if (b(i, j - 1) && (mask & (1 << tmp)))
            moves[3] = tmp;
    }
    int solve(int mask, int last) {
        if (dp[mask][last] != -1)
            return dp[mask][last];
        dp[mask][last] = 0;
        mov(f1(last), mask);
        vector<int> pm = moves;
        for (int i : pm) {
            if (i == -1) continue;
            dp[mask][last] += solve(mask ^ (1 << last), i);
        }
        return dp[mask][last];
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        g.swap(grid);
        n = g.size();
        m = g[0].size();
        int N = m * n, MASK = (1 << N) - 1;
        dp.resize((1 << N), vector<int>(N, -1));
        moves.resize(4);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 1) {
                    s = f(i, j);
                    dp[1 << s][s] = 1;
                }
                else if (g[i][j] == 2) {
                    e = f(i, j);
                    ee = (1 << e);
                }
                else if (g[i][j] == -1)
                    MASK &= ~(1 << (f(i, j)));
            }
        }
        return solve(MASK, e);
    }
};