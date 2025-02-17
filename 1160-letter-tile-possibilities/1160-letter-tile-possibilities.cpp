class Solution {
    int n;
    int ans{0};

public:
    void solve(string& tiles, vector<int>& fr) {
        for (auto& x : fr) {
            if (x > 0) {
                x--;
                ans++;
                solve(tiles, fr);
                x++;
            }
        }
    }

    int numTilePossibilities(string tiles) {
        n = tiles.size();
        vector<int> fr(26);

        for (auto& x : tiles)
            fr[x - 'A']++;

        solve(tiles, fr);

        return ans;
    }
};