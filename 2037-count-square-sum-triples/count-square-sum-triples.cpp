class Solution {
public:
    int countTriples(int n) {
        int br = 0;
        for(int a = 1; a <= n; a++) {
            for(int b = a; a*a + b*b <= n * n; b++) {
                int c = sqrt(a*a + b*b);
                if((c * c) == (a * a + b * b)) br++;
            }
        }
        return br<<1;
    }
};