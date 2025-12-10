class Solution {
public:
    const int M = 1e9 + 7;
    int countPermutations(vector<int>& com) {
        int mini = M, n = com.size(), ctr = n - 1;
        long long res = 1;
        for(int i = 0; i < n; i++){ 
            if(i) mini = min(mini, com[i]);
            if(ctr) res *= ctr--;
            if(res >= M) res %= M;
        }
        return (mini <= com[0]) ? 0 : res;
    }
};