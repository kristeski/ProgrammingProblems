class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int md = 0, ost = 0;
        for(int i : nums) {
            md += i;
            ost += i % k;
        }
        md %= k;
        if(ost >= md)
            return md;
        return -1;
    }
};