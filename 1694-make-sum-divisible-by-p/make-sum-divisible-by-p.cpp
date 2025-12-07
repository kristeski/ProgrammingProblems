class Solution {
public:
    const int M = 1e9 + 7;
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int, int> mp;
        long long t = 0;
        for(int i : nums)
            t += i;
        int tar = (t % p);
        int curr = 0; int best = nums.size();
        if(tar == 0) return 0;
        mp[0] = -1;
        for(int i = 0; i < nums.size(); i++) {
            curr = (curr + nums[i]) % p;
            mp[curr] = i;
            auto it = mp.find((p + curr - tar)%p);
            if(it != mp.end()) 
                best = min(best, i - (*it).second);
        }
        return (best != nums.size()) ? best : -1;
    }
};