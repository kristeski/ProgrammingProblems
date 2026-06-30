class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<vector<int>> pos(3);
long long br = 0;

for (int i = 0; i < s.size(); i++) {
    char c = s[i];
    int indx = c - 'a';
    pos[indx].push_back(i);
}


for(int i = 0; i < s.size(); i++) {
    int found = s[i] - 'a';
    int maxi = -1;
    bool p = false;
    for(int j = found + 1; j < found + 3; j++) {
        int val = j % 3;
        int f = lower_bound(pos[val].begin(), pos[val].end(), i + 1) - pos[val].begin();
        if (f >= pos[val].size() || p == true) {
            maxi = f = -1;
            p = true;
        }
        else
            f = pos[val][f];
        maxi = max(maxi, f);
    }
    if(maxi != -1)
       br += s.size() - maxi;
}
return br;
    }
};