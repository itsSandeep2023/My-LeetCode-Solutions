class Solution {
public:
    string minWindow(string s, string t) {
        ios::sync_with_stdio(false);
        
        int FP[256] = {0};
        int FS[256] = {0};

        for(const auto& ch : t)
            FP[ch]++;

        int cnt{0};
        int start{0};
        int start_idx{-1};
        int minSoFar = INT_MAX;
        int window_size {0};

        for(int i{0};i<s.size();i++)
        {
            char ch = s[i];
            FS[ch]++;

            if(FP[ch]!=0 and FS[ch] <= FP[ch])
            {
                cnt++;
            }

            if(cnt == t.size())
            {
                while(FP[s[start]]==0 or FS[s[start]] > FP[s[start]])
                {
                    FS[s[start]]--;
                    start++;
                }

                int window_size =  i - start + 1;

                if(window_size < minSoFar)
                {
                    minSoFar = window_size;
                    start_idx = start;
                }
            }
        }

        if(start_idx == -1) return "";

        return s.substr(start_idx, minSoFar);
    }
};