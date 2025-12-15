class Solution {
public:
    long long getDescentPeriods(vector<int>& p) {
        long long res = p.size();
        int l = 0;
        for (int i = 1; i < p.size(); i++) {
            if (p[i - 1] - p[i] != 1) {
                int len = i - l;
                res += 1LL*(len - 1) * len / 2;
                l = i;
            }
        }
        if (p.size() >= 2 && l < p.size() - 1) {
            int len = p.size() - l;
            res += 1LL * (len - 1) * len / 2;
        }
        return res;
    }
};