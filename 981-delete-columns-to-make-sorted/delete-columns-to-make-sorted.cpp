class Solution {
public:
    int minDeletionSize(vector<string>& s) {
       int n = s.size(), m = s[0].size();
       int ctr = 0;

       for(int row = 0; row < m; row++) {
            for(int rrow = 1; rrow < n; rrow++) {
                if(s[rrow][row] < s[rrow - 1][row]) {
                    ctr++;
                    break;
                }
            }
       }
       return ctr;
    }
};