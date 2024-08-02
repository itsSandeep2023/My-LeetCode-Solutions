class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int cnt{0};

        for(const auto& x: nums)
        {
            if(x==1)
                cnt++;
        }

        int mcnt{0};
        int ccnt{0};
        int i{0};
        int j{0};
        
        while(j<cnt)
        {
            ccnt+=nums[j++];
        }

        mcnt = max(mcnt, ccnt);

        int n = nums.size();

        while(i<n)
        {
            j=j%n;
            ccnt+= nums[j++] - nums[i++];
            mcnt = max(mcnt, ccnt);
        }

        return cnt - mcnt;
    }
};