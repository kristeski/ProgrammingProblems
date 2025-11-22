class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int br = 0;
        for(int i : nums) {
            if(i%3 == 0)
                continue;
            else 
                br++;
        }
        return br;
    }
};