class Solution {
public:
    bool doesValidArrayExist(vector<int>& der) {
        return accumulate(der.begin(), der.end(), 0)%2==0;
    }
};