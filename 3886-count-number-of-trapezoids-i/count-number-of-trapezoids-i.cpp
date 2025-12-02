class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> mp;
        for(auto &v : points) 
            mp[v[1]]++;
        long long pa = 0, ans = 0;
        const int M = 1e9 + 7;
        for(auto &[_, i] : mp) {
            long long chose = 1LL * i *(i - 1) / 2;
            ans += chose * pa;
            pa += chose;
        }
        return ans % M;
    }
};