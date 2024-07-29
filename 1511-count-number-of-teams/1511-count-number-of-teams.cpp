class Solution {
public:
    int numTeams(vector<int>& rating) {
        ios::sync_with_stdio(false);
        
        int n = rating.size();

        int ans{0};

        for(int i{1};i<n-1;i++)
        {
            int ls{0}, rs{0},lm{0},rm{0};

            for(int j{0};j<i;j++)
            {
                if(rating[j]<rating[i])
                    ls++;
                else if(rating[j]>rating[i])
                    lm++;
            }

            for(int j{n-1};j>i;j--)
            {
                if(rating[j]<rating[i])
                    rs++;
                else if(rating[j]>rating[i])
                    rm++;
            }

            ans+=ls*rm + lm*rs;
        }

        return ans;
    }
};