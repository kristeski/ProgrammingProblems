class Solution {
public:
    long long maxRunTime(int n, vector<int>& b) {
        sort(b.begin(), b.end());
        vector<int> l = vector<int>(b.begin() + b.size() - n, b.end());
        long long extra = 0, rez = *l.begin();
        int indx = 0;
        for(int i = 0; i < b.size() - n; i++)
            extra += b[i];

        for(int i = 1; i < n; i++) {
            int val = (l[i] - l[i - 1]);
            if(extra >= i * val) {
                extra -= i * val;
                rez += val;
                indx = i;
            }
            else 
                break;
        }
        rez += extra / (indx + 1);
        return rez;
    }
};