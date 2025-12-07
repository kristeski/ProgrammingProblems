class Solution {
public:
    int countOdds(int low, int high) {
        int br = 0;
        if(low % 2 == 1) {
            low++;
            br++;
        }
        if(low > high)
            return br;
        if(high % 2 == 1) {
            high--;
            br++;
        }
        br += (high - low) / 2;
        return br;
    }
};