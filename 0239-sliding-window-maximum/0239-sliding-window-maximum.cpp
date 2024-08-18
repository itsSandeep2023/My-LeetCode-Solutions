class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];

            while (!dq.empty() && dq.back() < num) {
                dq.pop_back();
            }
            dq.push_back(num);

            if (i >= k && nums[i - k] == dq.front()) {
                dq.pop_front();
            }

            if (i >= k - 1) {
                ans.push_back(dq.front());
            }
        }

        return ans;        
    }
};