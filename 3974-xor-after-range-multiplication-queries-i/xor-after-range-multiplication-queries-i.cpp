class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int M = 1000000007;
        for(const auto &q : queries) {
            int i = q[0];
            const int x = q[1];
            const int k = q[2];
            const int val = q[3];
            for(; i <= x; i += k) 
                nums[i] = (1LL * nums[i] * val) % M;
        }
        int rez = 0;
        for(int i : nums) {
            rez ^= i;
        }
        return rez;
    }
};