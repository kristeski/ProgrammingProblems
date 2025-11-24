class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size(), val = 0;
        vector<bool> v(n, false);
        for(int i = 0; i < n; i++){ 
            val = ((val << 1) + nums[i])%5;
            if(val == 0)
                v[i] = true;
        }
        return v;
    }
};