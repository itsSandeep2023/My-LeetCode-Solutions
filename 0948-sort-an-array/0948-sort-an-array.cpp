class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        ios::sync_with_stdio(false);
        
        priority_queue<int, vector<int>, greater<int> > q;
        
        for(auto x: nums)
        {
            q.push(x);
        }
        
        for(int i{0}; i<nums.size(); i++)
        {
            nums[i] = q.top();
            q.pop();
        }               
                        
        return nums;        
    }
};