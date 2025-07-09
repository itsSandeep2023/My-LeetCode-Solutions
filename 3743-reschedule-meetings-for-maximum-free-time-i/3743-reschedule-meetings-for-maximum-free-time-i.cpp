class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

       vector<int> diff;

        diff.push_back(startTime[0]);

       for(int i{1}; i<n; i++)
       {
            diff.push_back(startTime[i] - endTime[i-1]);
       }

       diff.push_back(eventTime - endTime[n-1]);

        int ans{0};
        int cmax{0};
        int cnt{0};

        int i{0};
        int j{0};


        while(i<=n)
        {
            if(cnt>k)
            {
                cnt--;
                cmax -= diff[j];
                j++;
            }

            cmax += diff[i];
            cnt++;
            i++;

            ans = max(ans, cmax);
        }
        
        return ans;
    }
};