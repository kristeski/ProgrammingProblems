class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> s;
        vector<int> res;
        res.reserve(nums.size());
        for(int i = 0; i < k; i++) {
            while(!s.empty() && nums[s.back()] < nums[i])
                s.pop_back();
            s.push_back(i);
        }
        res.push_back(nums[s.front()]);
        for(int i = k; i < nums.size(); i++){ 
            while(!s.empty() && nums[s.back()] < nums[i])
                s.pop_back();
            s.push_back(i);
            while(s.front() < i - k + 1)
                s.pop_front();
            res.push_back(nums[s.front()]);
        }
        return res;
    }
};