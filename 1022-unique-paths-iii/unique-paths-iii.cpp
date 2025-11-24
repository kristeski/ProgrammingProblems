class Solution {
public:
    int K; // number of free cells (including start and end)
    vector<pair<int,int>> coords; // index -> (i,j)
    vector<int> neighMask; // neighMask[u] bitmask of neighbors indices
    int startIdx, endIdx;
    vector<int> memo; // -1 = unknown, otherwise ways

    int getIdx(int mask, int u) { return mask * K + u; }

    int dfs(int mask, int u) {
        int idx = getIdx(mask, u);
        if (memo[idx] != -1) return memo[idx];
        if (mask == (1 << u)) {
            // base: only u left set; valid only if u == startIdx
            return memo[idx] = (u == startIdx) ? 1 : 0;
        }
        int ways = 0;
        int candidates = neighMask[u] & (mask ^ (1 << u));
        while (candidates) {
            int v = __builtin_ctz(candidates);
            candidates &= candidates - 1;
            ways += dfs(mask ^ (1 << u), v);
        }
        return memo[idx] = ways;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> id(n*m, -1);
        for (int i=0;i<n;i++) for (int j=0;j<m;j++) {
            if (grid[i][j] != -1) {
                id[i*m+j] = coords.size();
                coords.push_back({i,j});
            }
        }
        K = coords.size();
        neighMask.assign(K, 0);
        for (int u = 0; u < K; ++u) {
            auto [i,j] = coords[u];
            const int di[4] = {1,-1,0,0}, dj[4] = {0,0,1,-1};
            for (int d=0; d<4; ++d) {
                int ni = i+di[d], nj = j+dj[d];
                if (ni>=0 && nj>=0 && ni<n && nj<m && id[ni*m+nj] != -1)
                    neighMask[u] |= (1 << id[ni*m+nj]);
            }
            int val = grid[i][j];
            if (val == 1) startIdx = u;
            if (val == 2) endIdx = u;
        }

        int fullMask = (1 << K) - 1;
        memo.assign((1<<K) * K, -1);
        return dfs(fullMask, endIdx);
    }
};
