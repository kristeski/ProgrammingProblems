class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& b) {
        vector<vector<int>> v;
        unordered_map<int, int>mp, prev, nex;
        sort(b.begin(), b.end());
        int indx = -1;
        
        for (auto& vec : b) {
            if (mp.find(vec[0]) == mp.end()) mp[vec[0]] = ++indx;
            nex[vec[1]]++;
        }
        v.resize(indx + 1);
        int br = 0;
        for (auto& vec : b) v[mp[vec[0]]].push_back(vec[1]);
        for (int i = 0; i < indx; i++) {
            for (int j = 0; j < v[i].size(); j++) {
                nex[v[i][j]]--;
                if (j > 0 && j < v[i].size() - 1 && prev[v[i][j]] && nex[v[i][j]]) br++;
                prev[v[i][j]]++;
            }
        }
        return br;
    }
};