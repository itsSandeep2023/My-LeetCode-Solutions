class Solution {
public:
    int countDays(int days, vector<vector<int>>& meet) {
        int n = meet.size();

        sort(meet.begin(), meet.end());

        int ans{0};
        int last{0};
        
        for(auto& vec: meet)
        {
            if(vec[0] - last - 1 > 0)
                ans += vec[0] - last - 1;
            
            last = max(vec[1], last);
        }

        if(days - last > 0)
                ans += days - last;

        return ans;
    }
};