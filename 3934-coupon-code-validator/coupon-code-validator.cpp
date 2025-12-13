class Solution {
public:
vector<string> validateCoupons(const vector<string>& code,
                               const vector<string>& businessLine,
                               const vector<bool>& isActive) {
    int n = (int)code.size();
    unordered_set<string> allowed = {"electronics","grocery","pharmacy","restaurant"};
    unordered_map<string,int> order = {
        {"electronics", 0},
        {"grocery",     1},
        {"pharmacy",    2},
        {"restaurant",  3}
    };

    vector<pair<int,string>> valid; 

    for (int i = 0; i < n; ++i) {
        if (!isActive[i]) continue;               
        const string &s = code[i];
        if (s.empty()) continue;         

        bool ok = true;
        for (unsigned char ch : s) {
            if (!(isalnum(ch) || ch == '_')) { 
                ok = false;
                break;
            }
        }
        if (!ok) continue;

        const string &b = businessLine[i];
        if (!allowed.count(b)) continue;     

        valid.emplace_back(order[b], s);
    }

    sort(valid.begin(), valid.end(), [](const pair<int,string>& a, const pair<int,string>& b){
        if (a.first != b.first) return a.first < b.first;
        return a.second < b.second; 
    });

    vector<string> result;
    result.reserve(valid.size());
    for (auto &p : valid) result.push_back(p.second);
    return result;
}


};