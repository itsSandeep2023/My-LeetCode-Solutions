class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans{0};

        for(int i{0}, n = arr.size(); i<n; i++)
        {
            if(arr[i] > i)
            {
                int mx = arr[i];
                while(i<mx)
                {
                    i++;
                    mx = max(mx, arr[i]);
                }
            }
            ans++;
        }

        return ans;
    }
};