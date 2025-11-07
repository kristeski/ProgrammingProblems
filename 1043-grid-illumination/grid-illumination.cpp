class Solution {
public:
    //RiciBoss
    unordered_map<int, int>rdiag, ldiag, col, row; // first koristime za koja dijag, col ... second kolku upaleni.
    unordered_set<long long> lp;
    vector<int> ans;
    int n;
    int f(int row, int col) {
        if(row < col)
            return col - row + n;
        return row - col;
    }
    long long f1(int row, int col) {
        return 1LL * row * n + col;
    }
    vector<vector<int>> getnei(int row, int col) {
        vector<vector<int>> res;
        for(int i = -1; i < 2; i++) {
            for(int j = -1; j < 2; j++) {
                if(row + i < 0 || row + i >= n || col + j < 0 || col + j >= n)
                    continue;
                if(lp.find(f1(row + i, col + j)) != lp.end()) 
                    res.push_back({row + i, col + j});
            }
        }
        return res;
    }
    bool ansq(const vector<int>&q) {
        bool b = false;
        if(row[q[0]] || col[q[1]] || rdiag[q[0] + q[1]] || ldiag[f(q[0], q[1])])
            b = true;
        vector<vector<int>> nei = getnei(q[0], q[1]);
        for(auto &u : nei) {
            row[u[0]]--;
            col[u[1]]--;
            rdiag[u[0] + u[1]]--;
            ldiag[f(u[0], u[1])]--;
            lp.erase(f1(u[0], u[1]));
        }
        return b;
    }
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        this->n = n;
        ans.resize(queries.size());


        for(auto &i : lamps) {
            if(lp.find(f1(i[0], i[1])) != lp.end())
                continue;
            ldiag[f(i[0], i[1])]++;
            rdiag[i[0] + i[1]]++;
            row[i[0]]++;
            col[i[1]]++;
            lp.insert(f1(i[0], i[1]));
        }

        for(int i = 0; i < queries.size(); i++) 
            ans[i] = ansq(queries[i]);
        return ans;
    }
};
