class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        vector<int>v;
        v.reserve(n);
        long long sum = 1LL * n * (n + 1) / 2;
        target = sum - target;
        if(target < 0 || target > 2*sum || target%2)
            return v;
        int num = n;
        bitset<100001> bs(0);
        while(target){
            if(target <= 2*num) {
                v.push_back(-(target/2));
                bs[target/2] = 1;
                target = 0;
            }
            else {
                v.push_back(-num);
                bs[num] = 1;
                target -= 2*num;
                num--;
            }
        }
        for(int i = 1; i <= n; i++) {
            if(bs[i])
                continue;
            v.push_back(i);
        }
        return v;
    }
        
        
};