class Solution {
public:

	static bool custsort(const vector<string>& s1, const vector<string>& s2) {
		if (s1[1] != s2[1]) return stoi(s1[1]) < stoi(s2[1]);
		if (s1[0] != s2[0]) return s1[0] == "OFFLINE" ? true : false;
		return false;
	}
	vector<int> getindx(const string& s) {
		int pre = 0;
		vector<int> v;
		for (auto c : s) {
			int asval = c - '0';
			if (asval >= 0 && asval <= 9)
				pre = pre * 10 + asval;
			else if (c == ' ') {
				v.push_back(pre);
				pre = 0;
			}
		}
		v.push_back(pre);
		return v;
	}
	vector<int> countMentions(int n, vector<vector<string>>& ev) {
		sort(ev.begin(), ev.end(), custsort);
		int all = 0;
		vector<int> nexton(n, -1), res(n, 0);
		for (auto& v : ev) {
			int time = stoi(v[1]);
			string type = v[0], tag = v[2];
			if (type == "MESSAGE") {
				if (tag == "ALL") all++;
				else if (tag == "HERE") {
					for (int i = 0; i < n; i++) 
						if (nexton[i] <= time) res[i]++;
				}
				else {
					vector<int> info = getindx(v[2]);
					for (int i : info) res[i]++;
				}
			}
			else if (v[0] == "OFFLINE") 
				nexton[stoi(v[2])] = stoi(v[1]) + 60;
		}
		for (int& i : res) i += all;
		return res;
	}
};