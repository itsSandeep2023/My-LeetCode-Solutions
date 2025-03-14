class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans{0};
        bool flag = false;

        for(auto& x : nums)
        {
            if(x==0 and flag == false)
            {
                ans++;
                flag = !flag;
            }
            else if(x == 1 and flag == true)
            {
                ans++;
                flag = !flag;
            }
        }

        return ans;
    }
};