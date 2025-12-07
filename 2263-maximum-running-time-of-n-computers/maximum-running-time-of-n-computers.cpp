class Solution {
public:
    long long maxRunTime(int n, vector<int>& b) {
        long long sp = 0;
        for(int p : b) sp += p;
        long long lo = 0, hi = sp / n, t;

        while(lo < hi) {
            t = (lo + hi + 1) / 2;
            long long extra = 0;
            
            for(long long i : b)
                extra += min(i, t);
            
            if(extra >= t * n)
                lo = t;
            else 
                hi = t - 1;
        }
        return lo;
    }
};