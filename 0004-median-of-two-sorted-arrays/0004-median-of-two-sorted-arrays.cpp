class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        
        for(int a: nums1)
        {
            v.push_back(a);
        }
        
        for(int a: nums2)
        {
            v.push_back(a);
        }
        
        sort(v.begin(), v.end());
        int n = v.size();
        
        return n%2?v[n/2]:((v[n/2-1]+v[n/2])/double(2));
    }
};