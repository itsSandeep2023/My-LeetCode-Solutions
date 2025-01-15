class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int numBits{0};

        int p = (1 << (int)log2(num2));
        while (p > 0) {
            if (num2 & p)
                numBits++;
            p = p >> 1;
        }

        int x{0};
        p = (1 << (int)log2(num1));

        while (p > 0 and numBits > 0) {
            if (num1 & p) {
                numBits--;
                x |= p;
            }
            p = p >> 1;
        }

        p = 1;
        while (numBits > 0) {
            if (!(x & p)) {
                x |= p;
                numBits--;
            }

            p = p << 1;
        }

        return x;
    }
};