class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        int m = batteries.size();
        if (m < n) return 0;

        sort(batteries.begin(), batteries.end());

        long long extra = 0;
        for (int i = 0; i < m - n; ++i) {
            extra += batteries[i];
        }

        vector<int> live(batteries.end() - n, batteries.end());

        for (int i = 0; i < n - 1; ++i) {
            long long need = (long long)(i + 1) * (live[i + 1] - live[i]);
            if (extra < need) {
                return (long long)live[i] + extra / (i + 1);
            }
            extra -= need;
        }

        return (long long)live[n - 1] + extra / n;
    }
};