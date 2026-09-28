class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            res |= (carry << i);
            if ((a & (0b1 << i) ^ (b & (0b1 << i)))) {
                if ((res & (0b1 << i)) == 0) {
                    res |= (0b1 << i);
                    carry = 0;
                } else {
                    res -= (0b1 << i);
                    carry = 1;
                }
            } else if ((a & (0b1 << i) & (b & (0b1 << i)))) {
                carry = 1;
            } else {
                carry = 0;
            }
        }

        return res;
    }
};
