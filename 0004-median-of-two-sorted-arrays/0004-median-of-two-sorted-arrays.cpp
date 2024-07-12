class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        
        int i{0}, j {0};

        while(i<nums1.size() and j<nums2.size())
        {
            if(nums1[i]<nums2[j])
            {
                v.push_back(nums1[i++]);
            }
            else
            {
                v.push_back(nums2[j++]);
            }
        }

        while(i<nums1.size())
        {
            v.push_back(nums1[i++]);
        }

        while(j<nums2.size())
        {
            v.push_back(nums2[j++]);
        }
        
        int n = v.size();
        
        return n%2?v[n/2]:((v[n/2-1]+v[n/2])/double(2));
    }
};