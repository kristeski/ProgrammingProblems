class Solution {
public:
    int countCollisions(string dir) {
        int n = dir.size();
        int col = 0;
        for (int i = 0; i < n; i++) {
            int j = i;
            if (dir[i] == 'S') {
                while (j < n && dir[j] == 'S')
                    j++;
                i = j - 1;
            }
            else if (dir[i] == 'R') {
                while (j < n && dir[j] == 'R')
                    j++;
                if (j < n) {
                    col += j - i;
                    col += (dir[j] == 'L');
                }
                i = j;
            }
            else {
                while (j < n && dir[j] == 'L')
                    j++;
                if (i) col += j - i;
                i = j - 1;
            }
        }
        return col;
    }
};