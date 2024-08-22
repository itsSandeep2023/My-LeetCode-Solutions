class Solution {
public:
    int findComplement(int num) {
        return num ^ ((1U << ((int)(log2(num)) + 1)) - 1);
    }
};