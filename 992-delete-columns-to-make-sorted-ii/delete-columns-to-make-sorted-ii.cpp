class Solution {
private:
    int isGreater(const string& s1, const string& s2, const bitset<101>& bs){
        for(int i = 0; i < s1.size(); i++){
            if(bs[i] == 0){
                if(s1[i] < s2[i]){
                    return -1;
                }
                else if(s1[i] > s2[i]){
                    return i;
                }
            }
        }
        return -1;
    }
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        bitset<101> bits;        

        for(int i = 1; i < strs.size(); i++){
            int col = isGreater(strs[i - 1], strs[i], bits);
            if(col != -1){                    
                ans++;
                bits[col] = 1;
                i = 0;                              
            }
        }        
        
        return ans;
    }
};