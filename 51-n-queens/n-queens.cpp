class Solution {
public:
    //RiciBoss
    int ans, n;
    vector<vector<string>> res;
    vector<string> curr;
    vector<bool> col, diagL, diagR;
    int f(int row, int col) {
        if(row < col)
            return col - row + n;
        return row - col;
    }
    void rec(int row, int rem) {
        if(!rem) {
            ans++;
            res.push_back(curr);
            return;
        }
        for(int i = 0; i < n; i++) {
            int iro = f(i, row);
            if(!col[i] && !diagL[iro] && !diagR[i + row]) {
                string s(n, '.');
                s[i] = 'Q';
                col[i] = diagL[iro] = diagR[i + row] = true;
                curr.push_back(s);
                rec(row + 1, rem - 1);
                col[i] = diagL[iro] = diagR[i + row] = false;
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        col.resize(n, false); diagL.resize(2 * n, false);
        diagR.resize(2 * n, false);
        this->n = n;
        rec(0, n);
        return res;
    }
};