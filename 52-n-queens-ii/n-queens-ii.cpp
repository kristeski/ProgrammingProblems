class Solution {
public:
    //RiciBoss
    vector<bool> cols, diagL, diagD;
    int ans, n1;
    int f(int row, int col) {
        if(row < col)
            return col - row + n1;
        return row - col;
    }
    void rec(int row, int rem) {
        if(!rem) {
            ans++;
            return;
        }
        for(int i = 0; i < n1; i++){
            if(!cols[i] && !diagL[f(row, i)] && !diagD[row + i]) {
                cols[i] = diagL[f(row,i)] = diagD[row + i] = true;
                rec(row + 1, rem - 1);
                cols[i] = diagL[f(row, i)] = diagD[row + i] = false;
            }
        }
    }
    int totalNQueens(int n) {
        ans = 0; n1 = n;
        cols.resize(n, false);
        diagL.resize(2 * n, false);
        diagD.resize(2 * n, false); 
        rec(0, n);
        return ans;
    }
};