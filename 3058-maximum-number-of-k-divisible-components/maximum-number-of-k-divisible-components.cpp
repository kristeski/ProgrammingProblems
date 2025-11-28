class Solution {
public:
    using ll = long long;
    int rez = 0, jk;
    vector<vector<int>> adj;
    vector<ll> dp;
    ll dfs(int nd = 0, int par = -1) {
        for(int nei : adj[nd]){
            if(nei == par) continue;
            dp[nd] += dfs(nei, nd);
        }
        if(dp[nd] % jk == 0) {
            rez++;
            return 0;
        }
        return dp[nd];
   }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        adj.resize(n);
        dp.resize(n);
        for(int i = 0; i < n - 1; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        jk = k;
        for(int i = 0; i < n; i++)
            dp[i] = 1LL*values[i];
        dfs();
        return rez;
    }
};