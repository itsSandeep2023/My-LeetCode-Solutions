class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        sort(horizontalCut.rbegin(), horizontalCut.rend());
        sort(verticalCut.rbegin(), verticalCut.rend());

        long long i = 0;  
        long long j = 0;  
        long long hp = 1;
        long long vp = 1;
        long long ans = 0;

        while (i < horizontalCut.size() || j < verticalCut.size()) {
            if(i < horizontalCut.size() && j < verticalCut.size())
            {
                if (horizontalCut[i] >= verticalCut[j]) {
                    ans += horizontalCut[i] * vp;
                    hp++;
                    i++;
                } else {
                    ans += verticalCut[j] * hp;
                    vp++;
                    j++;
                }
            }
            else
            {
                if (i < horizontalCut.size()) {
                    ans += horizontalCut[i] * vp;
                    i++;
                }
                else if (j < verticalCut.size()) {
                    ans += verticalCut[j] * hp;
                    j++;
                }
            }
        }


        return ans;
    }
};