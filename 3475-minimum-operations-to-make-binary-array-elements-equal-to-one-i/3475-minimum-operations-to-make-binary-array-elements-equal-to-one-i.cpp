class Solution {
public:
    
    void flip(int &i)
    {
        if(i==0)
            i=1;
        else
            i=0;
    }
    
    int minOperations(vector<int>& nums) {
        int ans{0};
        
        for(int i{0}; i+3 <= nums.size();i++)
        {
            if(nums[i]==0)
            {
                ans++;
                flip(nums[i]);
                flip(nums[i+1]);
                flip(nums[i+2]);
            }
        }
        
        return nums[nums.size()-1] and nums[nums.size() - 2] ? ans:-1;        
    }
};