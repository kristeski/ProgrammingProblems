class Solution {
public:
    int n;
    const int inf = 1000000000;
    vector<int> dp;
    int top_down(int indx, const vector<int> &v) {
        if(dp[indx] != inf) return dp[indx];
        int j = v[indx];
        for(int i = indx + 1; i <= min(n-1, indx + j); i++) 
            dp[indx] = min(dp[indx], top_down(i, v) + 1);
        return dp[indx];
    }
    int jump(vector<int>& nums) {
        n = nums.size();
        dp.resize(n, inf);
        dp[n - 1] = 0;
        return top_down(0, nums);
    }
};