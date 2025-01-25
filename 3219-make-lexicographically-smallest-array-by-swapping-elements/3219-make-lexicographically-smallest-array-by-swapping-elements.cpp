class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> vec;

        for (int i{0}; i < n; i++)
            vec.push_back({nums[i], i});

        sort(vec.begin(), vec.end());

        vector<int> curr;
        int l{0};
        curr.push_back(vec[0].second);

        for (int i{1}; i < n; i++) {
            if (vec[i].first - vec[i - 1].first <= limit) {
                curr.push_back(vec[i].second);
            } else {
                sort(curr.begin(), curr.end());
                for (auto& x : curr) {
                    cout << x << " " << vec[l].first << " -> ";
                    nums[x] = vec[l].first;
                    l++;
                }
                cout << endl;
                curr.clear();
                curr.push_back(vec[i].second);
            }
        }

        sort(curr.begin(), curr.end());
        for (auto& x : curr) {
            nums[x] = vec[l].first;
            l++;
        }

        return nums;
    }
};