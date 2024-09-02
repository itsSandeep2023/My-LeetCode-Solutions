class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum{0};

        for(const auto& x: chalk)
            sum+=x;

        int left = k%sum;

        for(int i{0}; i<chalk.size(); i++)
        {
            if(chalk[i]>left)
                return i;

            left-=chalk[i];
        }        
        
        return -1;
    }
};