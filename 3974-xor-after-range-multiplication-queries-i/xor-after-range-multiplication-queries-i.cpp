class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int M = 1000000007;
        for(auto q : queries) {
            int i = q[0], x = q[1], k = q[2], val = q[3];
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