class Solution {
public:

    bool binary_search(vector<int>& vi, int x, int &y)
    {
        int l{0};
        int r = vi.size()-1;

        while(l<=r)
        {
            int mid = l + (r-l)/2;

            cout<<vi[mid];
            if(x<=vi[mid] and y>=vi[mid])
            {
                return true;
            }
            else if(vi[mid]<x)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return false;
    }

    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> vi;
        
        for(int i{1}; i<n; i++)
        {
            if((nums[i]&1) == (nums[i-1]&1))
            {
                vi.push_back(i);
            }
        }

        vector<bool> ans;

        for(auto vec : queries)
        {
            if(binary_search(vi, vec[0]+1, vec[1]))
            {
                ans.push_back(false);
            }
            else
            {
                ans.push_back(true);
            }
        }

        return ans;
    }
};