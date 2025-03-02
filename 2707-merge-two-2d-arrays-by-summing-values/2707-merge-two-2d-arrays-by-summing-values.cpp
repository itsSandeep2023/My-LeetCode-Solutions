class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                    vector<vector<int>>& nums2) {
        vector<vector<int>> ans;

        int n = nums1.size();
        int m = nums2.size();

        int i{0};
        int j{0};

        while (i < n and j < m) {
            if (nums1[i][0] == nums2[j][0])
                ans.push_back({nums1[i][0], nums1[i++][1] + nums2[j++][1]});
            else if (nums1[i][0] < nums2[j][0])
                ans.push_back(nums1[i++]);
            else
                ans.push_back(nums2[j++]);
        }

        while (i < n)
            ans.push_back(nums1[i++]);

        while (j < m)
            ans.push_back(nums2[j++]);

        return ans;
    }
};