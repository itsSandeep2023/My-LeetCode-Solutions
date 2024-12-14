class Solution {
    #define P pair<int, int>
public:
    long long continuousSubarrays(vector<int>& nums) {
        ios::sync_with_stdio(false);
        
        priority_queue<P> mxq;
        priority_queue<P, vector<P>, greater<P>> mnq;

        long long ans{0};
        int l{0};

        for(int i{0}, n= nums.size(); i<n;i++)
        {
            mxq.push({nums[i], i});
            mnq.push({nums[i], i});

            while(mxq.top().first - mnq.top().first > 2)
            {
                if(mxq.top().second < mnq.top().second)
                {
                    l = mxq.top().second + 1;
                    mxq.pop();
                }
                else
                {
                    l = mnq.top().second + 1;
                    mnq.pop();
                }

                while(!mxq.empty() and mxq.top().second < l)
                {
                    mxq.pop();
                }

                while(!mnq.empty() and mnq.top().second < l)
                {
                    mnq.pop();
                }
            }
            ans += i-l+1;
        }

        return ans;
    }
};