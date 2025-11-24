class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0;
        int br = 0;
        for(int i : nums) {
            if(i % 2 == i % 3 && !(i & 1)) {
                sum += i;
                br++;
            }
        }
        if(!br)
            return 0;
        return sum / br;
    }
};