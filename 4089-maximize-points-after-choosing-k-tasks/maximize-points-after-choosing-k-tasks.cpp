class Solution {
public:
    
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        priority_queue<pair<int, int>> pq;
        long long br = 0;
        int n = technique1.size();
        vector<bool> v(n, false);
        for(int i = 0; i < n; i++) 
            pq.push({technique1[i] - technique2[i], i});
        for(int i = 0; i < k; i++) {
            br += technique1[pq.top().second];
            v[pq.top().second] = true;
            pq.pop();
        }
        for(int i = 0; i < n; i++) {
            if(v[i]) continue;
            br += max(technique1[i], technique2[i]);
        }
        return br;
    }
};