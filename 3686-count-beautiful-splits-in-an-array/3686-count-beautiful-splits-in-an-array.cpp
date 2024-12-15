class Solution {
public:
    int beautifulSplits(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> t(n+1, vector<int>(n+1));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (nums[i] == nums[j]) 
                    t[i][j] = 1 + t[i + 1][j + 1];
            }
        }

        int ans{0};

       for(int i=0;i<n-2;i++) {
            for(int j=i+1;j<n-1;j++) {
                if((t[0][i+1]>=i+1 && j-i>=i+1) || (t[i+1][j+1]>=j-i && n-j>=j-i)) ++ans;
            }
        }

        return ans;
    }
};