class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        for(int i{0}, n = prices.size(); i<n; i++)
        {
            for(int j{i+1}; j<n; j++)
            {
                if(prices[j]<=prices[i])
                {
                    prices[i]-=prices[j];
                    break;
                }
            }
        }

        return prices;
    }
};