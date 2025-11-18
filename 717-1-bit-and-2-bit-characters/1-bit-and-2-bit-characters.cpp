class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int lb = 0;
        for(int i = 0; i < bits.size()-1; i++) {
            if(lb == i) {
                if(bits[i] == 0)
                    lb++; 
            }   
            else 
                lb = i + 1;
        }
        return lb == bits.size() - 1;
    }
};