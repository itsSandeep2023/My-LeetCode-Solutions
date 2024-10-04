class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        vector<int> sk(1001, 0);

        int sum{0};
        for (const auto& x : skill) {
            sk[x]++;
            sum+=x;
        }

        int teams = n/2;
        if(sum%teams != 0)
            return -1;

        int target = sum/teams;
        
        long long ans{0};

        for (const auto& x : skill) {
            int t = abs(target - x);

            if (sk[t] > 0) {
                ans += x * t;
                sk[t]--;
            } else {
                return -1;
            }
        }

        ans /= 2;
        return ans;
    }
};